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




