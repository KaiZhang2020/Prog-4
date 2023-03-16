#include "inventory.h"

Inventory::Inventory()
{
   
}

Inventory::~Inventory()
{
    
}


bool Inventory::insert(Movie toInsert)
{
    if (toInsert.genre == "C")
    {
        classics.push_back(toInsert);
    }
    else if (toInsert.genre == "F")
    {
        comedies.push_back(toInsert); 
    }
    else if (toInsert.genre == "D")
    {
        dramas.push_back(toInsert); 
    }
}

bool Inventory::isEmpty()
{

}

void Inventory::display()
{
    try
    {
        cout << "-----------------------" << endl;
        cout << "Comedies:" << endl << endl;
        cout << "Genere" << setw(10)
             << "Media" << setw(15) << "Title" << setw(10) << "Director" << setw(5)
             << "Year" << setw(5)
             << "Stock" << endl;
        for (int i = 0; i < comedies.size(); i++)
        {
            comedies[i].display();
        }
        cout << "-----------------------" << endl;
        cout << "Classics:" << endl;
        cout << "Genere" << setw(10)
             << "Media" << setw(15) << "Title" << setw(10) << "Director" << setw(5)
             <<"Month"<< setw(5) << "Year" << setw(5)
             << "Stock" << endl;
        for (int i = 0; i < classics.size(); i++)
        {
            classics[i].display();
        }
        cout << "-----------------------" << endl;
        cout << "Dramas:" << endl;
        cout << "Genere" << setw(10)
             << "Media" << setw(15) << "Title" << setw(10) << "Director" << setw(5)
             << "Year" << setw(5)
             << "Stock" << endl;
        for (int i = 0; i < dramas.size(); i++)
        {
            dramas[i].display();
        }
    }
    catch (const exception &e)
    {
        cerr << "display invetory error" << '\n';
    }
}

bool Inventory::ComedyMethod(string action, string title, int year){
    for (int i = 0; i < comedies.size(); i++)
    {
        if (comedies[i].title == title && comedies[i].year == year)
        {
            if (action == "B")
            {
                if (comedies[i].stock - 1 < 0)
                {
                    cout << "Error: Movie is Out of Stock." << endl; 
                    return false;
                }
                else 
                {
                    comedies[i].stock = comedies[i].stock - 1; 
                    return true; 
                }
            }
            else if (action == "R")
            {
                comedies[i].stock = comedies[i].stock + 1; 
                return true;
            }
            else if (action == "F")
            {
                return true; 
            }
        }
    }
    return false; 
}

bool Inventory::DramaMethod(string action, string director, string title){
    for (int i = 0; i < dramas.size(); i++)
    {
        if (dramas[i].director == director && dramas[i].title == title)
        {
            if (action == "B")
            {
                if (dramas[i].stock - 1 < 0)
                {
                    cout << "Error: Movie is Out of Stock." << endl; 
                    return false;
                }
                else 
                {
                    dramas[i].stock = dramas[i].stock - 1; 
                    return true; 
                }
            }
            else if (action == "R")
            {
                dramas[i].stock = dramas[i].stock + 1; 
                return true;
            }
        }
    }
    return false; 
}

bool Inventory::ClassicMethod(string action, int month, int year, string majorActor){
    for (int i = 0; i < classics.size(); i++)
    {
        if (classics[i].majorActor == majorActor && month == classics[i].month && year == classics[i].getYear())
        {
            if (action == "B")
            {
                if (classics[i].stock - 1 < 0)
                {
                    cout << "Error: Movie is Out of Stock." << endl; 
                    return false;
                }
                else 
                {
                    classics[i].stock = classics[i].stock - 1; 
                    return true; 
                }
            }
            else if (action == "R")
            {
                classics[i].stock = classics[i].stock + 1; 
                return true;
            }
        }
    }
    return false;
}

void Inventory::customerHistoryAdd(int id, string ptype, string director, string title){
    if(ptype == "R"){
        returnMovie r = returnMovie(ptype, director, title);
        customerHistory[id].push_back(r);
    }else if(ptype == "B"){
        Borrow r = Borrow(ptype, director, title);
        customerHistory[id].push_back(r);
    }
}

void Inventory::printCustomerHistory(int id, string pname)
{
    cout << "History for " + pname<< endl;
    for (int i = 0; i < customerHistory[id].size(); i++)
    {
        customerHistory[id][i].display();
    }
    cout << endl << endl;
}