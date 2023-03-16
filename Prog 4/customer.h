#ifndef customer_h
#define customer_h

#include <iostream>
#include <fstream>
#include <vector>
#include "transaction.h"
using namespace std;

class Customer {
    public:
        Customer();
        Customer(string, string, int);
        ~Customer();

        void addTransact(Transaction*);
        void displayHistory();

        void displayCustomer();

        int getID();
        string getFirstName();
        string getLastName();

        bool operator==(Customer&);
        bool operator!=(Customer&);

    private:
        int id;
        string FirstName;
        string LastName;
        vector<Transaction*> history;
};


#endif