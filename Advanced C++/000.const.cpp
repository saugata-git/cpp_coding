#include <iostream>

// const
// -A compile time constraint that an object can not be modified 


int main() {
    const int i = 9;
    // i = 6; give u compile time error

    const int *p1 = &i; //data is const, pointer is not
    // *p1  = 5; // assignment will  not work as data is const 
    p1++; //pointer arithmatic will work
   
    int j =10;
    int* const p2 = &j;   // pointer is const ,data is not const
    j++;
    // p2++; //pointer arithmatic will not work as pointer is const

    const int k =  20; 
    const int* const p3 = &k;   //data and pointer both are const
    // k++;   will not work as const
    // p3++;  will not work as const


    int const *p4 = &i;  //data is const
    const int *p4 = &i;  //data is const ,same as above 
    
    //If const is on the left of *, data is const
    //If const is on the right of *, pointer is const


   return 0;
}
/*************************************************************************/

#include <iostream>

// const
// -A compile time constraint that an object can not be modified 


int main() {
    const int i = 9;
    // i = 6; give u compile time error

    const_cast<int&>(i) = 6;  //will chang i to 6 ...constness is gone
    
    int j = 10;
    static_cast<const int&>(j);    // make j a const  modification is not allowed
    //j++; give u compile time error

   /*
   Why use const
      a.) Guard against inadvertent write to the variable.
      b.) Self documenting.
      c.) Enable compiler to do more optimization, making code tight
      d.) const means the variable can be put in ROM. 
   */
    return 0;
}
