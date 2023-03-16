#ifndef classic_h
#define classic_h

#include <fstream>
#include <iostream>
#include "movie.h"

using namespace std;

class Classic : public Movie
{
public:
    Classic();
    ~Classic();
};

#endif