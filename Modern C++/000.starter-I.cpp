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
     i++;           //chnages the values in v 
}
































