#include <iostream>
#include<iterator>
#include <vector>

/**
 * @brief Initializer List c++11
 * all STL containers has initializer list
*/

std::vector<int> v = {1, 2, 3, 4};    //calling  initializer list constructor

//Define your own initializer_list constructor :
#include<initializer_list>

class boVector {
    std::vector<int> m_vec;
    public:
    boVector(const initializer_list<int>& v){
        for(initializer_list<int>::iterator itr = v.begin(); itr!= v.end(); ++itr){
            m_vec.push_back(*itr);
        }
    }
};

boVector v = {1, 2, 3, 4};
boVector v{1, 2, 3, 4};  //effectively the same


/**
 * @brief Uniform Initialization as all use curly brace
*/
//C++ 03
class dog{      //Aggregate class or struct
    public:
        int age;
        std::string name;
};

dog d1 = {5 , "Henry"}; //Aggregate Initialization

//C++ 11 extended the scope of curly brace initialization
class dog{
    public:
       dog(int age, string name) {...};
}

dog d1 = {5, "Henry"};

/* Uniform Initialization Search Order :
*  1.Initializer_list constructor
*  2.Regular constructor that takes the appropriete parameters
*  3.Aggregate initializer
*/

dog d1{3};

class dog{
    public:
    int age;        //3rd choice
    
    dog(int a) {
        age = a;     //2nd choice
    }
    
    dog(const initialier_list<int>& vec){   //1st choice
        age  = *(vec.begin());
    }
};


/**
 * @brief  auto type
 * 
 */

// c++ 03 
for (std::vector<int>::iterator it = vec.begin(); it!=vec.end(); ++it) {
    m_vec.push_back(*it);
}

// c++ 11: use auto type
for (auto it = vec.begin(); it!=vec.end(); ++it) {
    m_vec.push_back(*it);
}
auto a = 6;       // integer
auto b = 9.6;     // double
auto c = a;       // integer

/**
 * @brief for each
 * 
 */

//C++ 03:
 for (std::vector<int>::iterator itr=v.begin(); itr!=v.end(); ++itr) {
     std::cout<< (*itr);
 }

//C++ 11:
for(int i : v) {    //works on any class that has begin() and end()
     std::cout<< i;     //randomly  access
} 

for(auto& i: v){
     i++;           //changes the values in v 
}


/**
 * @brief nullptr
 * 
 *  To replace NULL=0 in C++ 03
 */

void foo(int i) {
    std::cout << "foo_int" <<std::endl;
}

void foo(char* pc){
    std::cout << "foo_char*" <<std::endl;
}

int main() {
    foo(NULL); //Ambiguity

    //C++ 11
    foo(nullptr); //call foo(char*)
}



/**
 * @brief enum class
 * 
 */

// C++ 03
enum apple {green_a, red_a};
enum orange {big_o, small_o};
apple a = green_a;
orange o = big_o;

if( a==o ){
    cout << "green apple and big orange are the same\n"; //o/p
}
else{
    cout << "green apple and big orange are not the same\n";
}

//C++ 11 introduce enum classes
enum class apple {green, red};
enum class orange {big, small};

apple a = apple::green;
orange o = orange::big;

if( a==o ){
    cout << "green apple and big orange are the same\n"; //o/p
}
else{
    cout << "green apple and big orange are not the same\n";
}

//Compile fails because we have not define == (apple,orange) [equal operator]


/**
 * @brief static_assert
 * 
 */

//run-time asssert
   assert(myPointer!= NULL);

//Compile time assert (C++ 11)
   static_assert(sizeof(int) == 4)


/**
 * @brief Delegating Constructor
 * 
 */


//can only work in JAVA not in C++ 
class dog {
    public: 
      dog() { ... }                            //invoke 2 dogs
      dog(int a) { dog(); doOtherThings(a);}
};

// C++ 03:
class dog {
   init() { ... };
   public:
   dog() { init(); }
   dog(int a){ init(); doOtherThings(); }
};

/* Cons:
* 1.Cumbersome code.
* 2.init() could be invoked by other functions.
*/

//C++ 11:
class dog {
    public:
    dog() { ... }
    dog(int a) : dog() { doOtherThings(); }
}

//Limitation: dog() has to be called first.




























