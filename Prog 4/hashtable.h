#ifndef hashtable_h
#define hashtable_h
#include <iostream>
#include "customer.h"
using namespace std;

class HashTable {
    public:
        HashTable();
        ~HashTable();
        void addCustomer(Customer&);
        bool hasCustomer(int)const;
        Customer getCustomer(int)const;

        Customer* table;
        bool* used;
        int tableSize = 1000;
        int size;
        int Hash(int) const;
};


#endif