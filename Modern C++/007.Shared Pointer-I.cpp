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
