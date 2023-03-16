#include "transaction.h"

Transaction::Transaction(){

}

Transaction::~Transaction(){

}

string Transaction::getType() const{
    return type;
}

string Transaction::getText() const{
    return text;
}

void Transaction::display(){
    if(type == "R"){
        cout << "Returned" << " " + text << endl;
    }else{
        cout << "Borrowed" << " " + text << endl;
    }
    
}