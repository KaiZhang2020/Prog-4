#include "movie.h"

Movie::Movie(){
    
}

Movie::Movie(string type, int pstock, string pdirector, string ptitle, int releaseYear){
    genre = type;
    title = ptitle;
    director = pdirector;
    year = releaseYear;
    stock = pstock;
}

Movie::Movie(string type, int pstock, string pdirector, string ptitle, string pmajorActor, int releaseYear, int releaseMonth){
    genre = type;
    title = ptitle;
    director = pdirector;
    year = releaseYear;
    stock = pstock;
    majorActor = pmajorActor;
    month = releaseMonth;
}


Movie::~Movie(){

}

void Movie::display(){
    if (genre == "C") {
    cout << genre << "          "<< "D          "<<  title  << setw(30) << director  << setw(5) <<  month << setw(5) <<  year << setw(5) << stock << endl;
  }
  if ((genre == "D") || (genre == "F")) {
    cout << genre << "          "<< "D          "<<  title << setw(30) <<  director << setw(5) <<  year << setw(5) << stock<<  endl;
  }
}

string Movie::getTitle(){
    return title;
}

string Movie::getDirector(){
    return director;
}

int Movie::getYear(){
    return year;
}

int Movie::getStock(){
    return stock;
}

string Movie::getGenere(){
    return genre;
}

void Movie::increaseStock(){
    stock++;
}

void Movie::decreaseStock(){
    stock--;
}

void Movie::increaseStock(int count){
    stock+=count;
}
