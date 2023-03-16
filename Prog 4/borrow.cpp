#include "borrow.h"

Borrow::Borrow(string ptype, string director, string title){
    type = ptype;
    text = title + " by " + director;
}

void Borrow::display(){
    cout << "Borrowed " << text << endl;
}