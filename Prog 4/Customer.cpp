#include "customer.h"

Customer::Customer(){

}

Customer::Customer(string firstname, string lastname, int cid){
    id = cid;
    FirstName = firstname;
    LastName = lastname;
}

Customer::~Customer(){
    for(int i = 0; i < history.size();i++){
        Transaction* temp = history[i];
        delete temp;
        temp = nullptr;
    }
}

void Customer::addTransact(Transaction* transact){
    history.push_back(transact);
}


void Customer::displayHistory(){
    if(history.size() == 0){
        cout << "No transaction for customer" << id << endl;
        return;
    }

    cout << "Transaction History for Customer" << id << " " << LastName << " " << FirstName << endl;
    for(int i = 0; i < history.size(); i++){
        Transaction* temp = history[i];
        cout << temp->getType() << " " << temp->getText() << endl; 
    }
    cout << endl;
}

void Customer::displayCustomer(){
    cout << FirstName << " " << LastName << " "<< id << endl;
}

int Customer::getID(){
    return id;
}

string Customer::getFirstName(){
    return FirstName;
}

string Customer::getLastName(){
    return LastName;
}

bool Customer::operator==(Customer& other){
    return id == other.id;
}
bool Customer::operator!=(Customer& other){
    return id != other.id;
}
