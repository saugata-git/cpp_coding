#include<bits/stdc++.h>
using namespace std;

/*
Compiler silently writes 4 functions if they are not explicitly declared:
1. Copy constuctor.
2. Copy Assignment Operator.
3. Destructor.
4. Default constructor (only if there is no constructor declared)
*/


class Dog {};

/* equivalent to */

class Dog {
    public:
       Dog(const Dog& rhs) { ... }; // Member by Member initialization
       Dog& operator=(const Dog& rhs) { ... }; //Member by Member copying
       Dog() {...};  // 1. Call base class's default constructor.
                     // 2. Call data members's default constructor.
       ~Dog() {...}; // 1. Call base class's destructor.
                     // 2. Call data members's destructor.
};
