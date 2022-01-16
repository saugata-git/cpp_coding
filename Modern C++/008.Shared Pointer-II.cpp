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
   shared_ptr<Dog> p1 = make_shared<Dog>("Tommy");
   shared_ptr<Dog> p2 = make_shared<Dog>("Tom");  // tom is top of stack
   p1 = p2; //Tommy is deleted  impiles  p1->p2
   p1 = nullptr; //Tommy is deleted 
   p1.reset(); //Tommy is deleted 

} 


int main(){
   foo();
   return 0;
}
/*********************************************************************************/


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
   shared_ptr<Dog> p1 = make_shared<Dog>("Tommy"); //using default deleter : operator delete
   shared_ptr<Dog> P2 = shared_ptr<Dog>(new Dog("Tom"),  //custom deleter
      [](Dog* p){
         cout << "Custom deleting. "; 
         delete p;
      }
   );

   shared_ptr<Dog> p3(new Dog[3]); //dog[1] and dog[2] have memory leaks.
   shared_ptr<Dog> p4(new Dog[3],
      [](Dog *p){
         delete[] p;    // All 3 dogs will be deleted when p4 goes out of scope
      }
   );
} 


/********************************************************************************/




















