#ifndef comedy_h
#define comedy_h

#include <fstream>
#include <iostream>
#include "movie.h"
using namespace std;

class Comedy: public Movie {
    public:
        Comedy();
        ~Comedy();

        virtual void setData(ifstream&);
        virtual void setTransData(ifstream&);

        // virtual bool operator>(const Movie&)const;
        // virtual bool operator<(const Movie&)const;
        // virtual bool operator==(const Movie&)const;
        // virtual bool operator!=(const Movie&)const;

        virtual Movie* insert(); //insert into the tree

};

#endif