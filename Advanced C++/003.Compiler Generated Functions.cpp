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
/*
Note :
1.They are public and inline.
2.They are generated only if they are needed.
*/


/*------------------------------------------------*/
/*
Example 1 : auto generated stuff by compiler
   1. Copy Constructor.  - no 
   2. Copy Assignmnet Operator. - yes
   3. Destructor. - no
   4. Default Constructor. -no
*/


class Dog {
   public:
    string m_name;
    //string &m_name;   if we use this instead compiler will through 
    //an error as it is not member by member copy 
    //compiler gen Copy Assignmnet Operator cannot handel it
    Dog(string name = "Bob"){
        m_name = name;
        cout << name << "is born." << endl;
    }
    ~Dog() {
        cout<< m_name << "is destroyed.\n" << endl;
    }

};

int main() {
  Dog dog1("Henry");
  Dog dog2;
  dog2 = dog1;
}


/*
OUTPUT :
Henry  is born.
Bob is born.
Henry is destroyed.
Henry is destroyed.
*/

/*------------------------------------------------*/
/* Example 2 : */


class collar {
    public:
    collar(string collar){
        std::cout<< "collar is born. \n";
    }
};

class dog {
     collar m_collar;
};

int main() {
    dog dog1;
}

// as inside coller already a constuctor is there 
// default constructpor can not generated there
// so the deafult consatructor inside dog will not be genegrated 
// code will not compile 


/*------------------------------------------------*/
/* Example 2 : */

class collar {
    public:
    collar(){
        std::cout<< "collar is born. \n";
    }
};

class dog {
     collar m_collar; //data_member
};

int main() {
    dog dog1;
}

// code will compile 


/*------------------------------------------------*/
/* Example 3 : */


class collar {
    public:
    collar(){
        std::cout<< "collar is born. \n";
    }
}

class dog {
     collar m_collar; // data_member
     string &m_name; // uninitialized reference 
};

int main() {
    dog dog1;
}

// code will compile not compile


/*------------------------------------------------*/
/*C++ 11 Update: */
class dog {
   public:
       dog() = default;  // will give you control to generate  
                         //compiler generated default constructor
       dog(string name) {...};
};
