#include <iostream>
#include <string>
#include <memory>  //smart pointer
using namespace std;

class Dog{
   string name_;
   public:
      Dog(string name) {
         cout << "Dog is created: " << name << endl;
         name_ = name;
      }
      Dog() {
         cout <<"Nameless dog created." <<endl;
         name_ ="nameless";
      }
      ~Dog() { 
         cout << "dog is destroyed: " << name_ <<endl;
      }
      void bark() {
         cout << "Dog " << name_ <<"rules!" << endl;
      }
};

void foo(){
  Dog* p = new Dog("Tom");
  //......
  delete p;   //if commented memory leak
  //...
  p->bark();   // p is dangling pointer  - undefined behavior
}

// Teadious work -- resolution smart pointers



/*-----------------------------------------------------------*/

#include <iostream>
#include <string>
#include <memory>  //smart pointer
using namespace std;

class Dog{
   string name_;
   public:
      Dog(string name) {
         cout << "Dog is created: " << name << endl;
         name_ = name;
      }
      Dog() {
         cout <<"Nameless dog created." <<endl;
         name_ ="nameless";
      }
      ~Dog() { 
         cout << "dog is destroyed: " << name_ <<endl;
      }
      void bark() {
         cout << "Dog " << name_ <<" rules!" << endl;
      }
};

void foo(){
  shared_ptr<Dog> p(new Dog("Tom"));  //pointer_count = 1  //not exception safe
  // 2 steps -> 1."Tom has created ." 2. "p is created"
  {
     shared_ptr<Dog> p2 = p;  //pointer_count = 2
     p2->bark(); cout<< p.use_count() << endl;
  }
  //pointer_count = 1
  p->bark();   // p is dangling pointer  - undefined behavior
} //pointer_count = 0;

// Teadious work -- resolution smart pointers

int main(){
   foo();
  
   /*
   //BAD Idea
   Dog* d = new Dog("Tommy");
   shared_ptr<Dog> p(d);  //p.use_count() = 1   //when p goes out of scope d get destroyed 
   shared_ptr<Dog> p2(d); //p2.use_count() = 1  //when p2 goes out of scope d get destroyed  - which is undefiend  behavior
   //An object should be assigned to a smart pointer as soon as it created. Raw pointer should not be used
   */

   //short cut 
   // Dog* d = new Dog("Tommy");   //BAD Idea
   shared_ptr<Dog> p = make_shared<Dog>("Tommy"); //faster and exception safer 
   
   // you can also use derference 
   (*p).bark();
   
   //you can use casting with shared pointers
     //static_pointer_cast
     //dynamic_pointer_cast
     // const_pointer_cast
  
   return 0;
}


