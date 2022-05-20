/*------------------------------------------------*/
// Calling Virtual Functions in Constructor or Destructor 

class Dog {
public:
    Dog() { 
        cout << "Dog born." << endl; 
    }
    void bark() { 
        cout << "I am a just a dog." <<endl;
    }
    void seeCat() {
        bark();
    }
};

class Yellowdog : public Dog {
public:
  Yellowdog() {
      cout << "Yellow dog born." <<endl;
  }
  void bark() {
      cout << "I am a yellow dog" <<endl;
  }
};


int main() {
   Yellowdog d;
   d.seeCat();
  return 0; 
}

/*
Dog born.
Yellow dog born.
I am a just a dog.
*/



/*--------------------------------------------------------------*/
