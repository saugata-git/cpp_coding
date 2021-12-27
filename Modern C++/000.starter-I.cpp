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































