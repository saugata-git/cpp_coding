#include <iostream>
#include <string>
#include <memory>  
#include <vector>

// Resource Managing Class 

class Person{
public:
   Person(std::string name) : pName(new std::string(name)) { } 
   ~Person() {delete pName; }
   void printName() { std::cout << *pName; }
private:
  std::string* pName;
};


int main() {

   std::vector<Person> persons;
   persons.push_back(Person("Aloe"));  //object goes out of scope
   persons.front().printName(); //this will give us error pname is deleted
   
   std::cout << "Goodbye " <<std::endl;

}

/**
 * C++ 03 solution:
 * 1. define copy constuctor and copy assignment operator
 * 2. delete copy constuctor and copy assignment operator
 */


/******************************************************************************/
















