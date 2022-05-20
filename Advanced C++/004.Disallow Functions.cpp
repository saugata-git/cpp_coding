
#include<bits/stdc++.h>
using namespace std;


/*------------------------------------------------*/
class OpenFile {
public:
    OpenFile(string filename) {
        cout << "Open a file  :" << filename << endl;
    }
    //OpenFile(OpenFile& rhs) = delete;  // deleted compiler // code still will not compile any how
    member_function(OpenFile& f) {
            OpenFile f2(f);              // code still will not compile any how as 
                                         // private constructors body is not defined
    }
    private:  
      OpenFile(OpenFile& rhs);   // private copy constructor  // code still will not compile any how
      OpenFile& operator = (const OpenFile& rhs);
      //~OpenFile(); //no nobody can use open private destructor
      ~OpenFile() {
           cout << " OpenFile destructed "  << endl;
      }
};

int main() {
   
    OpenFile f(string("FILE_NAME"));    
    OpenFile f2(f);    // 2 objects trying to access same file
 
}

/*----------------------------------------------------------------*/
class OpenFile {
public:
    OpenFile(string filename){
        cout << "Open a file  :" << filename << endl;
    }
    void destroyMe(){
        delete this;
    }
private:                 //private destructor
    ~OpenFile () {
        cout << "OpenFile destructed ." << endl;
    }
};

int main() {
   
    /*
      This will not work  
      OpenFile f(string("FILE_NAME")); 

      This will not work  
      OpenFile f(string("FILE_NAME"));  //on stack
      f.destroyMe();
    */
    OpenFile* f = new OpenFile(string("FILE_NAME"));  //  on heap
    f->destroyMe();
    
}
