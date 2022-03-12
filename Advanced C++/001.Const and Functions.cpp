#include <iostream>

// const used with functions
class Dog {
    int age;
    std::string name;
public:
    Dog() { 
       age =3; 
       name ="dummy";
    }  
    /*
    void setAge(int& a){
        age = a;
        a++;  // will chnage value of a or passed param
    } */

    void setAge(const int& a){   //const reference
        age = a;
        //a++;  // will not work and will not change value of a or passed param
    } 
};
int main() {
    Dog d;
    int i = 9;
    d.setAge(i);
    std::cout<< i << std::endl;
    return 0;
}
