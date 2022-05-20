#include<bits/stdc++.h>
using namespace std;


/*------------------------------------------------*/
/*
* Prevent Exceptions from Leaving Destructors .
*/
class dog {
    public:
     string m_name;
     dog(string  name) {
        m_name = name;
        cout<< name << " is born." <<endl;
     }
     ~dog() {
        cout<< m_name << "is destroyed.\n" <<endl;
     }

     void bark() {
        //....
     }
     // ...
};


int main() {

  try {
      dog dog1("Henry");
      dog dog2("Bob");
      throw 20;
      dog1.bark();
      dog2.bark();

  } catch (int e) {
      cout << e << " is caught" <<endl;
  }
   
  return 0; 
}

/*
OUTPUT :
Henry is born.
Bob is born.
Bob is destroyed.
Henry is destroyed.
20 is caught.
*/

/*------------------------------------------------*/

/*------------------------------------------------*/

/*
* Prevent Exceptions from Leaving Destructors .
*/
class dog {
    public:
     string m_name;
     dog(string  name) {
        m_name = name;
        cout<< name << " is born." <<endl;
     }
     ~dog() {
        cout<< m_name << "is destroyed.\n" <<endl;
        throw 20;   // We should not throw exception from a destructor
     }

     void bark() {
        //....
     }
     // ...
};


int main() {

  try {
      dog dog1("Henry");
      dog dog2("Bob");
      dog1.bark();
      dog2.bark();

  } catch (int e) {
      cout << e << " is caught" <<endl;
  }
   
  return 0; 
}

??? This program will crash badly.... as two exceptions are pending at same time ...


