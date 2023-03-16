#include "store.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile1("data4customers.txt"); // customer
    if (!infile1)
    {
        cout << "Error reading customers file)" << endl;
        return 1;
    }
    ifstream infile2("data4movies.txt"); // movies
    if (!infile2)
    {
        cout << "Error reading movies file" << endl;
        return 1;
    }
    ifstream infile3("data4commands.txt"); // transaction
    if (!infile3)
    {
        cout << "Error reading commands file" << endl;
        return 1;
    }
    Store movieStore;
    movieStore.customerListInit(infile1);
    movieStore.inventoryInit(infile2);
    movieStore.processTransactions(infile3);
    
    return 0;
}
