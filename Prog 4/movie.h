#ifndef movie_h
#define movie_h

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Movie
{
public:
    Movie();
    Movie(string, int, string, string, int);
    Movie(string, int, string, string,string,int, int);
    virtual ~Movie();
    virtual void display();
    //virtual void setData(ifstream &);
    //virtual void setTransData(ifstream &);

    string getTitle();
    string getDirector();
    int getYear();
    int getStock();
    string getGenere();
    void increaseStock();
    void decreaseStock();

    void increaseStock(int count);

    // virtual bool operator>(const Movie &);
    // virtual bool operator<(const Movie &);
    // virtual bool operator==(const Movie &);
    // virtual bool operator!=(const Movie &);

    //virtual Movie *insert();

    string genre;
    string title;
    string director;
    int stock;
    int year;
    string majorActor;
    int month;
};

#endif