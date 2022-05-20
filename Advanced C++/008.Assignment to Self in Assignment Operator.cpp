
/*------------------------------------------------*/
/*
* Handle self-assignmnet in operator=
*
* Operator overload: exploite people's intuiton ans reduce their learning curve
*/



dog dd;
dd = dd; // Looks Silly 

dogs[i] = dogs[j]; // Looks lees Silly


/* Implemeting Assignment Operator */
class collar;
class dog {
    collar* pCollar;
    dog& operator=(const dog& rhs) {
        delete pCollar;    //  but self assignment like  dd = dd is risky as pCollar gets deleted 
        pCollar = new collar(*rhs.pCollar);
        return *this;
    }
};

/*****************************************************/
/* solution */
//solution 0
class collar;
class dog {
    collar* pCollar;
    dog& operator=(const dog& rhs) {
        if(this == &rhs){
            return *this;
        }
        delete pCollar;  
        pCollar = new collar(*rhs.pCollar);
        return *this;
    }
};

/******************************************************/
//solution 1
//Exception safe code
/* Implemeting Assignment Operator */
class collar;
class dog {
    collar* pCollar;
    dog& operator=(const dog& rhs) {
        if(this == &rhs){
            return *this;
        }
        collar* pOrigCollar = pCollar;
        pCollar = new collar(*rhs.pCollar); // what if *rhs.pCollar throws an exception
        delete pOrigCollar;  
        return *this;
    }
};

