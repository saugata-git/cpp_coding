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



