#include <iostream>
#include<iterator>
#include <vector>

/**
 * @brief override ( for virtual function)
 * To avoid inadertently create new function in derived classes.
 */

// C++ 03
class dog {
    virtual void A(int);
    virtual void B() const;
}

class yellowdog : public dog {
    virtual void A(float); //Created a new function      // will not override missed data type
    virtual void B(); //Created a new function           // will not override  missed  const
} 
//will  not help in polymorphism


//C++ 11
class dog {
    virtual void A(int);
    virtual void B() const;
    void C();
}

class yellowdog : public dog {
    virtual void A(float) override;  //Error: no function to override
    virtual void B() override;       //Error: no function to override 
    void C() override;               //Error: no function to override
}
//show you error message 



/**
 * @brief final( for virtual function and for class)
 */

class dog final {     //no class can be derived from dog 
    ...
};

class dog {
    virtual void bark() final;   //No class can override bark()
}


/**
 * @brief Compiler Generated Default Constructor
 */

class dog{
    dog(int age){}
};

dog d1; //Error: compiler will not generate the default constructor

//C++ 11:
class dog {
    dog(int age);
    dog() = default;   //Force compiler to generate the default constructor
}
/**
 * @brief delete keyword
 * 
 */

class dog {
    dog(int age) {}
}

dog a(2);
dog b(3.0);  // 3.0 is converted from double to int
a = b;       // Compiler generated assignment operator will work

//C++ 11:
class dog {
    dog(int age) {}
    dog(double ) = delete;
    dog& operator=(const dog&) = delete;
}

dog a(2);
dog b(3.0);  // compile time error
a = b;       // Compile time error


/**
 * @brief  constexpr
 * 
 */

int arr[6]; //OK

int A() { return 3;}
int arr[A()+3];     // Compile Error

//C++ 11
constexpr int A() { return 3};   // Forces the computation
                                 // to happen at compile time
int arr[A()+3];     // Create an array of size 6         

//Write faster program with constexpr

constexpr int cubed(int x){
    return x*x*x;
}

int y = cubed(1789); //computed at compile time


/**
 * @brief  New String Literals
 * 
*/

// C++ 03:
char* a = "string";

// C++ 11:
char* a = u8"string";     //to define an UTF-8 string.
char16_t* b = u"string";  //to define UTF-16 string.
char32_t* c = U"string";  //to define UTF-32 string.
char* d = R"string \\"    //to define raw string.


/**
 * @brief  lambda function
 * 
 */


/**
 * @brief  lambda function
 * 
 */

std::cout << [](int x,int y){ return x+y; }(3,4) << std::endl;     //output : 7
auto f = [](int x,int y){ return x+y;}
std::cout<< f(3,4) << std::endl;     //output : 7

template<typename func>
void filter(func f, std::vector<int> arr) {
    for(auto i : arr){
        if(f(i)){
            std::cout<< i <<std::endl;
        }
    }
}

int main(){ 
   std::vector<int> v = { 1, 2, 3, 4, 5, 6};
   filter([](int x) {return (x>3);}, v) ;  //output : 4, 5, 6   
   ....
   filter([](int x){ return (x>2 && x<5);}, v); //output : 3, 4


   int y = 4;
   filter([&](int x) { return (x>y);} ,v);   //output : 5, 6 
   //Note: [&] tells compiler that we want variable capture 
}



