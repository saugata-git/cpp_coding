/**
 * @brief User defined Literals
 */

/**
 * Literals are constansts.
 * 
 * C++ has 4 kinds of literals :
 *    integer         ------  45
 *    floating point  ------  4.5
 *    character       ------  'z'
 *    string          ------  "Dog" 
 */

// 45;  int literal
// 45u; unsigned int (suffix specifies type)
// 45l  long 

//C++ 99 :
long double height = 3.4;  // Metres ? Centimeters ? Inches ?


//Ideally, always attach units to the values:
// height = 3.4cm;
// ratio = 3.4cm /2.1 mm;   // ratio = 3.4 * 10 /2.1



/* ------------------------------------------------------------------------------------------- */

#include <iostream>
using namespace std;

/**
 * @brief User defined Literals
 */

//User defined literals
long double operator"" _cm(long double x) { return x*10; }
long double operator"" _m(long double x) { return x*1000; }
long double operator"" _mm(long double x) { return x; }

int main(){
   long double height = 3.4_cm;
   cout<< height << endl;
}



