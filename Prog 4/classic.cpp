#include "classic.h"

Classic::Classic() : Movie()
{

}

Classic::~Classic()
{

}

// bool Classic::operator>(const Movie &other) const
// {
//     const Classic &otherMovie = static_cast<const Classic &>(other);
//     if (year < otherMovie.year)
//     {
//         return true;
//     }
//     else if (year == otherMovie.year && actor_last_name < otherMovie.actor_first_name)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool Classic::operator<(const Movie &other) const
// {
//     const Classic &otherMovie = static_cast<const Classic &>(other);
//     if (year > otherMovie.year)
//     {
//         return true;
//     }
//     else if (year == otherMovie.year && actor_last_name > otherMovie.actor_first_name)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool Classic::operator==(const Movie &other) const
// {
//     const Classic &cMovie = static_cast<const Classic &>(other);
//     return (year == cMovie.year && month == cMovie.month);
// }

// bool Classic::operator!=(const Movie &other) const
// {
//     const Classic &cMovie = static_cast<const Classic &>(other);
//     return (year != cMovie.year || month != cMovie.month);
// }