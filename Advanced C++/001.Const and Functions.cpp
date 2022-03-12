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



/*****************************************************************************/

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
    
    // const parametes
    void setAge(const int a){   //not very use ful as pass by value or copy although const
        age = a;
    } 
    /*
    void setAge(int a){   // overloading will not be diffentiated
        age = a;
    }
    */    

/*
    // const return by value
    const std::string getName() {    //const is useless return copy of name which is temporary
        return name;
    }
*/
    // const return reference
    const std::string& getName() {    //improves effiecny and caller can not change the value
        return name;
    }

};

int main() {
    Dog d;
    const std::string& str= d.getName();
    std::cout << str << std::endl; 
    return 0;
}

/***************************************************************************/
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


    const std::string& getName() {    //improves effiecny and caller can not change the value
        return name;
    }
    
   // const function
   void printDogName() const {     
       // this type of const means this function can not change any of the member vairable of this class
       std::cout << "const  " << name << std::endl;
       //age++;  // not allowed
       //cant even call any other non cost function i.e calling getName() won't work.
   }
   
    // const and with out const overloading is possible
    void printDogName() {     
       // this type of const means this function can not change any of the member vairable of this class
       std::cout << "non - const  "<<  getName() << std::endl;
       //age++;  // not allowed
       //cant even call any other non cost function.
    }

};

int main() {
    Dog d;
    d.printDogName(); 
  
    const Dog d2; 
    d2.printDogName();

    return 0;
}
