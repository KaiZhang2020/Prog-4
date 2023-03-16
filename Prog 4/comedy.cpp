#include "comedy.h"

Comedy::Comedy() : Movie()
{
}
Comedy::~Comedy()
{
}

void Comedy::setData(ifstream &infile1)
{
    infile1.ignore();
    infile1 >> stock;

    infile1.ignore();
    getline(infile1 >> ws, director, ',');

    infile1.ignore();
    getline(infile1 >> ws, title, ',');

    infile1 >> year;
}

void Comedy::setTransData(ifstream &infile1)
{
    infile1.ignore();
    getline(infile1 >> ws, title, ',');
    infile1 >> year;
}

// bool Comedy::operator>(const Movie &other) const
// {
//     const Comedy &comedyMovie = static_cast<const Comedy &>(other);
//     if (title > comedyMovie.title)
//     {
//         return true;
//     }
//     else if (year > comedyMovie.year)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool Comedy::operator<(const Movie &other) const
// {
//     const Comedy &comedyMovie = static_cast<const Comedy &>(other);
//     if (title < comedyMovie.title)
//     {
//         return true;
//     }
//     else if (year < comedyMovie.year)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool Comedy::operator==(const Movie &other) const
// {
//     const Comedy &comedyMovie = static_cast<const Comedy &>(other);
//     return (title == comedyMovie.title && year == comedyMovie.year);
// }

// bool Comedy::operator!=(const Movie &other) const
// {
//     const Comedy &comedyMovie = static_cast<const Comedy &>(other);
//     return (title != comedyMovie.title || year != comedyMovie.year);
// }

Movie *Comedy::insert()
{
    return new Comedy();
}