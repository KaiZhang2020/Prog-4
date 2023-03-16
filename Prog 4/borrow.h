#ifndef borrow_h
#define borrow_h
#include <fstream>
#include <iostream>
#include "transaction.h"
using namespace std;

class Borrow:public Transaction {
    public:
        Borrow(string, string, string);
        void display();
};

#endif