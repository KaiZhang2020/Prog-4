#include "hashtable.h"

HashTable::HashTable(){
    table = new Customer[tableSize];
    used = new bool[tableSize];
    for (int i = 0; i < tableSize; i++) {
        used[i] = false;
    }
}

HashTable::~HashTable(){
    delete[] table;
    delete[] used;
}

void HashTable::addCustomer(Customer& toAdd){
    int index = Hash(toAdd.getID());
    while (used[index]) {
        if (table[index].getID() == toAdd.getID()) {
            std::cerr << "Error: customer already exists" << std::endl;
            return;
        }
        index = (index + 1); //probing
    }
    table[index] = toAdd;
    used[index] = true;
    size++;
}

bool HashTable::hasCustomer(int id)const{
    int index = Hash(id);
    while (used[index]) {
        if (table[index].getID() == id) {
            return true;
        }
        index = (index + 1) % tableSize;
    }
    return false;
}

Customer HashTable::getCustomer(int id)const{
    int index = Hash(id);
    while (used[index]) {
        if (table[index].getID() == id) {
            return table[index];
        }
        index = (index + 1) % tableSize;
    }
    std::cerr << "Error: customer not found" << std::endl;
    return Customer("", "", 0);
}

int HashTable::Hash(int id) const {
    return id % tableSize;
}
