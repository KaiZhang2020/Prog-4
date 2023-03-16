#ifndef returnMovie_h
#define returnMovie_h

#include <fstream>
#include <iostream>
#include "transaction.h"
using namespace std;

class returnMovie: public Transaction {
    public: 
        returnMovie(string, string, string);
        void display();
};

#endif