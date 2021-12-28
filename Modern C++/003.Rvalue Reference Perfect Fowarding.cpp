#include <iostream>
#include<iterator>
#include <vector>

// C++ 11 : Rvalue Reference
// 1. Moving Semantics
// 2. Perfect Forwarding
// Prerequisite: undersatnding of rvalue and lvalue


/**
 * @brief Perfect Forwarding
 * 
 */

class Vector{
    int size;
    double* arr_;
   public:
       Vector( const Vector& rhs) {   //Copy constructor  (deep copy)
            size = rhs.size;
            arr_ = new double[size];
            for( int i=0; i<size; i++){
                arr_[i] = rhs.arr_[i];
            }
       }

       Vector( Vector&& rhs) {   //Move constructor  (shallow copy)
            size = rhs.size;
            arr_ = rhs.arr_;
            rhs.arr_ = nullptr;
       } 
      ~Vector() { delete arr_; }
};

void foo(Vector v);     // Vector has both move constructor and copy constructor
Vector createVector();


// this kind of template will not forward perfectly  to foo.
template< typename T>
void relay(T arg) {
    foo(arg);
}


int main(){
    Vector reusable = createVector();
    foo(reusable);    // calls Copy Constructor

    ...
    foo(createVector());    // calls Move Constructor
    return 0;
}

/**
 *  1. No costly and unnecessary copy construction of Vector is made.
 *  2. ravlue is forwarded as rvalue, and lvalue is forwarded as lavlue.
 */



// Solution:
template< typename T>
void relay(T&& arg) {
    foo(std::forward<T>(arg));
}

//*Note: this will work because type T is a template type.

/**
 *  Reference Collapsing Rules (C++ 11 ):
 *  1. T& &   ==> T&
 *  2. T& &&  ==> T&
 *  3. T&& &  ==> T&
 *  4. T&& && ==> T&&
 */


template< class T>
struct remove_reference;     //it  removes reference on type T

//T is int&
remove_reference<int&>::type i;  //int i;

//T is int
remove_reference<int>::type i;  //int i;




template< typename T>
void relay(T&& arg) {       // universal reference
   ...
}

/**
 *  rvalue reference is specified with type&& .
 * 
 *  type&& is always rvalue reference ? -> No
 */

// T&& variable is initialized with rvalue =>  rvalue reference 
 relay(9); => T = int&& => T&& = int&& && = int&&

// T&& variable is initialized with lvalue =>  lvalue reference 
 relay(9); => T = int& => T&& = int& && = int&

     
     
/**
 *   T&& is Universal Reference : rvalue, lvalue , const , non const etc.
 *   But 2 condtions need to be made:
 *      1. T is a template type.
 *      2. Type deduction (reference collasping ) happens to T.
 *          -T is a function template type, not a class template.
 */     
     
 

/**
 *   T&& is Universal Reference : rvalue, lvalue , const , non const etc.
 *   But 2 condtions need to be made:
 *      1. T is a template type.
 *      2. Type deduction (reference collasping ) happens to T.
 *          -T is a function template type, not a class template.
 */

template< typename T>
void relay(T&& arg) {
    foo(std::forward<T>(arg));
}

//Implementation of std::forward()   casts the argument as per the relay function
template<class T>
T&& forward(typename remove_refernce<T>:: type& arg) {
    return static_cast<T&&> (arg);
} 
     
     
     
     
     
     
     
     
     
