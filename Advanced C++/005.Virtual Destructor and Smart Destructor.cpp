/*------------------------------------------------*/
class Dog {
public :
    
    virtual ~Dog() {      // if we dont use virtual keyword then 
                          //~Yellowdog() destructor will not be called
        cout << "Dog destroyed " << endl;
    }  
};

class Yellowdog : public Dog {
public:
   ~Yellowdog() {
       cout << "Yellow dog destroyed." <<endl;
    }
};

class DogFactory {
public:
   static Dog* createYellowDog() {
        return  (new Yellowdog());
   }
   // ... create other dogs
};


int main() {
    Dog* pd = DogFactory::createYellowDog();
    // ... Do something with pd
    delete pd;
    return 0;
};
