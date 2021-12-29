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

/*
//User defined literals    -- all happnes in runtime   -- costly 
long double operator"" _cm(long double x) { return x*10; }
long double operator"" _m(long double x) { return x*1000; }
long double operator"" _mm(long double x) { return x; }
*/

//---- compile time 
constexpr long double operator"" _cm(long double x) { return x*10; }
constexpr long double operator"" _m(long double x) { return x*1000; }
constexpr long double operator"" _mm(long double x) { return x; }


int main(){
   long double height = 3.4_cm;
   cout<< height << endl;
   cout<< (height+17.0_m) << endl;
   cout<< (170.0_mm/17.0_m) << endl;
}

/*-------------------------------------------------------------------------------*/

/**
 * @brief User defined Literals
 */

// Example:
int operator"" _bin(const char* str , size_t l){
   int ret = 0;
   for(int i=0 ; i<l ; i++){
      ret = ret << 1 ;
      if(str[i] == '1'){
          ret += 1; 
      } 
   }
   return ret;
}

int main(){
   cout << "110"_bin << endl;
   cout << "110000111010101001"_bin << endl;
   cout << "1111111"_bin << endl;
}

/*------------------------------------------------------------------------------*/


/* Restriction: it can only work with following  parameters.
   char const*
   unsigned long long 
   long double
   char const* , std::size_t
   wchar const* , std::size_t 
   char16_t const* , std::size_t
   char32_t const* , std::size_t
Note: return value can be of any types. */



