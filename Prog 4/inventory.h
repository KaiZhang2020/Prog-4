#ifndef inventory_h
#define inventory_h

#include <iostream>
#include <vector> 
#include <string>
#include "movie.h"
#include "transaction.h"
#include "borrow.h"
#include "returnMovie.h"
#include <map> 
using namespace std;

class Inventory
{
public:
    Inventory();
    ~Inventory();

    bool insert(Movie);
    bool retrieve(Movie &, Movie *&);
    bool isEmpty();
    void display();
    bool ComedyMethod(string, string, int);
    bool DramaMethod(string, string, string);
    bool ClassicMethod(string, int, int, string);
    void customerHistoryAdd(int, string, string, string);
    void printCustomerHistory(int, string);  
    

    vector<Movie> classics;         
    vector<Movie> comedies;         
    vector<Movie> dramas; 

    map<int, vector<Transaction>> customerHistory;

};

#endif