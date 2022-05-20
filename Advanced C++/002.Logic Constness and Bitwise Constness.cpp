#include<bits/stdc++.h>
using namespace std;

class BigArray {
    vector<int> v; //huge vector
    //int accessCounter;  // will give you compiler error
    mutable int accessCounter;  // logic constness


    int* v2;   //another int array

public:
   int getItem(int index) const {    // const function
       accessCounter++;   // will give you compiler error
        // or if you dont want to use mutable at all you can do this
        //const_cast<BigArray*>(this)->accessCounter++; 
       return v[index];
   }

   void setV2Item(int index ,int x) const {    // ok as its maintains bitwise constness of the class 
       *(v2+index) = x;
   }

   // quiz 
   const int*const fun(const int*const& p) const;
   /*
   
   1. fun(...) is a const function which guarantees not modify its data members ( v , accesscounter, v2's location )

   2. fun takes  arg (const int * const & p) which is
       (a reference to a const pointer) pointing to --> (const int)
         - which means the pointer is passed by reference and not by value to this function , so address of p is same in caller scope and in fun
         - also the pointer location cannot be changed as pointer itself is const. So p++ inside function is not possible.
        - Also the int value to which the pointer, is pointing to, cannot be changed as its const . So (*p)=5 is not possible

        const int* const fun(const int * const & p) const {
          //accessCounter++;  fun is const
          //p++;              p is const
          //*p = 5;           p points to const
          cout << "Address of p:" << p << endl; //same as in caller, 0044F92C
          return p;
         } 
         ...
        somewhere in main
        BigArray b;
        const int x = 9;
        const int* p = &x;
        cout << "Address of p:" << p << endl;  //0044F92C
 

    3. fun returns (const int* const) which is copy of temporary const pointer -->(pointing to const int).   
    So a const pointer by value is useless. The return value can be casted to const or non const pointer  eg.
       const int* rp = (b.fun(p));  //non-const ptr rp is now pointing to 0044F92C and *rp=9
       rp++ ; //OK

      //int m = (*(b.fun(p)))++; //trying to set non-const to const
      int n = *(b.fun(p));  //OK, n is 9
   */
};

int main() {
    BigArray b;
}
