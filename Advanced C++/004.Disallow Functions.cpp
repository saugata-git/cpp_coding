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
