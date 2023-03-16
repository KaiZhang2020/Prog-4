#include "returnMovie.h"

returnMovie::returnMovie(string ptype, string director, string title){
    type = ptype;
    text = title + " by " + director;
}

void returnMovie::display(){
    cout << "Returned " << text <<endl;
}
