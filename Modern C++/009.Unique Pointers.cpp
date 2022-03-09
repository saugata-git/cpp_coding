#include <iostream>
#include <string>
#include <memory>  


//Unique Pointers: exclusive ownership, light weight smart pointer.

class Dog{

public:
   std::string m_name;
   void bark() {
      std::cout << "Dog " << m_name << " rules!" << std::endl;
   }
   Dog() {
      std::cout<< "Nameless dog created. " << std::endl;
      m_name = "nameless";
   }
   Dog( std::string name){
      std::cout<< "Dog is created: " << name << std::endl;
      m_name = name;
   }
   ~Dog(){
      std::cout << "Dog is destroyed : " << m_name << std::endl;
   }
};

void test(){
   /*-------------------------------------
   
   Dog* pD = new Dog("Tom");
   pD->bark();
    //pD does a bunch of differnet things 
   delete pD; 

   ----------------------------------------*/
   

   /*--------------------------------------
  
   std::unique_ptr<Dog> pD(new Dog("Tommy"));
   pD->bark();
   // pD does a bunch of differnet things 
   //As we are using unique pointer its no longer needed
  
   ----------------------------------------*/


   /*----------------------------------------

   std::unique_ptr<Dog> pD(new Dog("Tommy"));
   pD->bark();
   Dog* p = pD.release();   // but did not destroy the object
   //gives you the raw pointer but if you use it auto-metic delete feature will be gone .

   if(!pD){
      std::cout<<"pD is empty. \n";
   }
   //unique_ptr giving up owner ship
   
   ------------------------------------------*/
   
   std::unique_ptr<Dog> pD(new Dog("Tommy"));
   pD->bark();
   //Dog* p = pD.release();
   //pD.reset(); //pD = nullptr;
   //pD.reset();
   pD.reset(new Dog("Aloe"));  // old objects destructor will be closed  //destroy the object

   if (!pD) {
      std::cout << "pD is empty. \n";
   } else {
      std::cout << "pD is not empty. \n";
   }
   
}

int main(){
   test();
}
