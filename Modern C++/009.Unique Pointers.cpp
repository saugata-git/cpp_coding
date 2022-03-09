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

/*-----------------------------------------------------------------*/
/* Two unique_ptr can not share the same object */

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
   std::unique_ptr<Dog> pD(new Dog("Tommy"));
   std::unique_ptr<Dog> pD2(new Dog("Aloe"));
   pD2->bark();
   pD2 = std::move(pD);
        // 1. Aloe is destroyed.
        // 2. pD becomes empty.
        // 3. pD2 onws Aloe.
   pD2->bark();
}

int main(){
   test();
}

/*----------------------------------------------------------*/




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

/* Two unique_ptr can not share the same object */
void f(std::unique_ptr<Dog> p){
   p->bark();  
   //dog will be destroyed inside this function
   //owner ship transfer from pD to p
}

//unique_ptr is passed by value will move symantics
std::unique_ptr<Dog> getDog() {
   std::unique_ptr<Dog> p(new Dog("Aloe"));
   return p;
}


void test(){
   std::unique_ptr<Dog> pD(new Dog("Tommy"));
   f(std::move(pD));
   if(!pD){
      std::cout <<"pD is empty. \n";
   }
   std::unique_ptr<Dog> pD2 = getDog();

  // std::unique_ptr<Dog[]> dogs(new Dog[3]);
}

int main(){
   test();
}



/*---------------------------------------------------*/


//Unique Pointers: can also be used as menber data

class Dog{
  // Bone* pB;
  std::unique_ptr<Bone> pB;   //This prevents memory leak even constructor fails.
public:
   std::string m_name;
   void bark() {
      std::cout << "Dog " << m_name << " rules!" << std::endl;
   }
   Dog() {
      pB = new Bone(); 
      /* if excxption thrown pB will never be deleted thats why use unique_ptr  */

      std::cout<< "Nameless dog created. " << std::endl;
      m_name = "nameless";
   }
   Dog( std::string name){
      std::cout<< "Dog is created: " << name << std::endl;
      m_name = name;
   }
   ~Dog(){
      delete pB;
      std::cout << "Dog is destroyed : " << m_name << std::endl;
   }
};












