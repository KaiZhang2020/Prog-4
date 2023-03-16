#ifndef store_h
#define store_h

#include <iostream>
#include <fstream>
#include <stack>

#include "customer.h"
#include "hashtable.h"
#include "inventory.h"

using namespace std;

class Store {
    public:
        Store();
        ~Store();
        void customerListInit(ifstream&);
        void inventoryInit(ifstream&);
        void processTransactions(ifstream&);

        void displayCustomerList();
        void displayInventory();

        bool addCustomer(Customer);
        bool findCustomer(int);
        Customer getCustomer(int);

    private:
        HashTable table; //customer table
        Inventory inv; //inventory

};

#endif