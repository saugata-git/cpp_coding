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


/*------------------------------------------------*/
// we can avoid this using  virtual keyword if we use hared pointer

class Dog {
public :
    
    ~Dog() {        // we can avoid this using  virtual keyword if we use hared pointer
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
   static shared_ptr<Dog> createYellowDog() {
        return  shared_ptr<Yellowdog>(new Yellowdog());
   }
   // ... create other dogs
};


int main() {
    shared_ptr<Dog> pd = DogFactory::createYellowDog();
    // ... Do something with pd
    //delete pd;
    return 0;
};

/* Note :
   unique_ptr only invoke Dog's destructor
   shared_ptr will invoke both destructor
   All classes in STL have no virtual destructor, so be careful inheriting from them.
*/
