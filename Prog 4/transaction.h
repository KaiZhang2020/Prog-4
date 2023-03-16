#ifndef transaction_h
#define transaction_h
#include <string>
#include <iostream>
using namespace std;

class Transaction {
    public:
        Transaction();
        ~Transaction();
        string getType() const;
        string getText() const;
        void display();

        string type;
        string text;
};

#endif