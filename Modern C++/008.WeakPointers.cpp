#include <iostream>
#include <memory>
using namespace std;


class Dog { 
    //shared_ptr<Dog> m_pFriend;  //cyclic reference
    weak_ptr<Dog> m_pFriend; //solution   //weak pointer has no wonership of the pointed object
                             //same as Dog* m_pFriend; // but no boday can delete weak pointer
    public:
        string m_name;
        Dog(string name){
            cout << "Dog "<< m_name <<" rules!" <<endl;
        }
        void bark() {
            cout << "Dog "<< m_name <<" rules!" << endl;
        } 
        ~Dog() {
            cout<< "dog is destroyed: "<< m_name <<endl;
        }
        void makeFriend( shared_ptr<Dog> f) { m_pFriend = f; }
};

//memory leaks - non of them get deleted after scope due to cyclinc reference 

int main(){

    shared_ptr<Dog> pD(new Dog("Tom"));
    shared_ptr<Dog> pD2(new Dog("Tommy"));
    pD->makeFriend(pD2);
    pD2->makeFriend(pD);

}
/****************************************************************/

#include <iostream>
#include <memory>
using namespace std;

class Dog { 
    weak_ptr<Dog> m_pFriend; 
    public:
        string m_name;
        Dog(string name){
            cout << "Dog "<< m_name <<" rules!" <<endl;
        }
        void bark() {
            cout << "Dog "<< m_name <<" rules!" << endl;
        } 
        ~Dog() {
            cout << "dog is destroyed: "<< m_name <<endl;
        }
        void makeFriend( shared_ptr<Dog> f) { m_pFriend = f; }
        void showFriend() {
           // cout << "My friend is :  "<< m_pFriend->m_name <<endl;    // can not compile - cant not be 
                                                                      // used as regular pointer
            if(!m_pFriend.expired()){                                                          
               cout << "My friend is :  "<< m_pFriend.lock()->m_name <<endl; //shared poiner out of weak pointer
               cout << " He is owned by "<< m_pFriend.use_count() << " pointers."<<endl;
            }
        }
};

int main(){

    shared_ptr<Dog> pD(new Dog("Tom"));
    shared_ptr<Dog> pD2(new Dog("Tommy"));
    pD->makeFriend(pD2);
    pD2->makeFriend(pD);
    showFriend();

}


