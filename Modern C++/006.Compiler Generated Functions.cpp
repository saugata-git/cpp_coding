#include <iostream>
using namespace std;

class Dog {} ; //not really empty some special finctions are there


/**
 * C++ 03:
 *  1. default constructor (generated only when no constructor is defined by user)
 *  2. copy constructor
 *  3. copy assignment operator
 *  4. destructor
 
 */


/**
 *  C++ 11:
 *  1. default constructor (generated only when no constructor is defined by user)
 *  2. copy constructor ( generated only if 5,6 not decleared by user)
 *  3. copy assignment operator ( generated only if 5,6 not decleared by user)
 *  4. destructor
 *  5. move constructor   (genereated only if 2,3,4,6 not decleard by user)
 *  6. move assignment operator (genereated only if 2,3,4,5 not decleard by user)
 */



class Dog {
   //C++ 03:
   Dog();                        //default constructor
   Dog(const Dog&);              //copy constructor
   Dog& operator=(const Dog&);   //copy assignment operator
   ~Dog();                       //destructor

   //C++ 11:
   Dog(Dog&&);                   //move constructor  
   Dog& operator=(Dog&&);        //move assignment operator            
};


// example 0
class Dog {}; 
// gererate -> 1,2,3,4,5,6

//example 1
class Cat {
    Cat(const Cat&) {} //copy constructor
};
// gererate -> 3,4

//example 2
class Duck {
    Duck(Duck&&) {} //move constructor
};
// gererate -> 4


class Frog {
    Frog(Frog&& ,int=0) {} //move constructor  // gererate -> 4
    Frog(int=0) {} //default constructor
    Frog(const Frog&, int=0) {} //copy constuctor
};

class Fish {
    ~Fish() {}
};
// gererate -> 1,2,3


