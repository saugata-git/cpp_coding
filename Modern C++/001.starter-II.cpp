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

//C++
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

