#include <iostream>
using namespace std;

class Dog {} ; //not really empty some special finctions are there


/**
 * C++ 03:
 *  1. default constructor (generated only when no constructor is defined by user)
 *  2. copy constructor
 *  3. copy assignment operator
 *  4. destructor
 
 */


/**
 *  C++ 11:
 *  1. default constructor (generated only when no constructor is defined by user)
 *  2. copy constructor ( generated only if 5,6 not decleared by user)
 *  3. copy assignment operator ( generated only if 5,6 not decleared by user)
 *  4. destructor
 *  5. move constructor   (genereated only if 2,3,4,6 not decleard by user)
 *  6. move assignment operator (genereated only if 2,3,4,5 not decleard by user)
 */
