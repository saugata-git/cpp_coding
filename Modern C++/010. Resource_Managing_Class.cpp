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
// c++ 11 sol :  delete copy constuctor 



class Person{
public:
   Person(std::string name) : pName(new std::string(name)) { } 
   Person(const Person& ) = delete;     //deleted copy constuctor //it wont compile
   ~Person() {delete pName; }
   void printName() { std::cout << *pName; }
private:
  std::string* pName;
};


int main() {

   std::deque<Person> persons;   //dont use vector as it always try to copy or move
   persons.emplace_back("Aloe");  //constuct the object inplace (in the space allocated to the vector)
   persons.front().printName(); 
   
   std::cout << " Goodbye " <<std::endl;

}

/****************************************************************************/

/**
 * C++ 11 solution
 * 
 */


class Person{
public:
   Person(std::string name) : pName(new std::string(name)) { } 
  // ~Person() {delete pName; }
   void printName() { std::cout << *pName; }
private:
  std::shared_ptr<std::string> pName;
};


int main() {

   std::vector<Person> persons;
 
   Person p("George");
   persons.push_back(p);
   persons.front().printName(); 
   
   std::cout << " Goodbye " <<std::endl;

}


/***********************************************************/
/**
 * C++ 11 solution
 * 
 */


class Person{
public:
   Person(std::string name) : pName(new std::string(name)) { } 
  // ~Person() {delete pName; }
   void printName() { std::cout << *pName; }
private:
  std::unique_ptr<std::string> pName;  //can't be copied only be moved
};


int main() {

   std::vector<Person> persons;
 
   Person p("George");
   persons.push_back(std::move(p));
   persons.front().printName(); 
   
   std::cout << " Goodbye " <<std::endl;

}



