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
/*------------------------------------------------*/
// Calling Virtual Functions in Constructor or Destructor 

class Dog {
public:
    Dog() { 
        cout << "Dog born." << endl; 
    }
    virtual void bark() { 
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
  virtual void bark() {              // dynamic binding
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
I am a yellow dog.
*/

/*------------------------------------------------*/

/*------------------------------------------------*/
// Calling Virtual Functions in Constructor or Destructor  -- Avoid it

class Dog {
public:
    Dog() { 
        cout << "Dog born." << endl; 
        bark();
    }
    virtual void bark() { 
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
  virtual void bark() {
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
I am a just a dog.
Yellow dog born.
I am a yellow dog.
*/

/*------------------------------------------------*/
// Calling Virtual Functions in Constructor or Destructor  -- Avoid it

class Dog {
public:
    Dog() { 
        cout << "Dog born." << endl; 
        bark();
    }
    virtual void bark() { 
        cout << "I am a just a dog." <<endl;
    }
    void seeCat() {
        bark();
    }
    ~Dog() {
        bark();
    }

};

class Yellowdog : public Dog {
public:
  Yellowdog() {
      cout << "Yellow dog born." <<endl;
  }
  virtual void bark() {
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
I am a just a dog.
Yellow dog born.
I am a yellow dog.
I am a just a dog.
*/
