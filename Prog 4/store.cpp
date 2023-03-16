#include "store.h"

Store::Store()
{
}

Store::~Store()
{
}

void Store::customerListInit(ifstream &infile1)
{
    string line;
    while(!infile1.eof()){
        getline(infile1, line);
        if(line.empty())
        {
            break;
        }
        stringstream parseLine(line);
        int ID;
        string firstName, lastName;
        parseLine >> ID >> lastName >> firstName;
        Customer newCustomer = Customer(firstName, lastName,ID);
        addCustomer(newCustomer);
    }
}

void Store::inventoryInit(ifstream &infile2)
{
    string line;
    while(getline(infile2,line))
    {
        stringstream ss(line);

        string movieType, 
            director, 
            title, 
            majorActor, 
            majorActorFirstName, 
            majorActorLastName, 
            temp;
        int stock, 
            releaseYear, 
            releaseMonth;

        getline(ss,movieType,',');
        getline(ss,temp,',');
        istringstream(temp) >> stock;
        getline(ss,director,',');
        getline(ss,title,',');

        if(movieType == "C")
        {
            getline(ss,majorActorFirstName,' ');
            getline(ss,majorActorLastName, ' ');
            majorActor = majorActorFirstName + majorActorLastName;
            getline(ss,temp,' ');
            getline(ss,temp,' ');
            istringstream(temp) >> releaseMonth;
            getline(ss,temp,' ');
            istringstream(temp) >> releaseYear;
            Movie newMovie = Movie("C", stock,director,title,majorActor,releaseYear,releaseMonth);
            inv.insert(newMovie);
        }
        else if(movieType == "F")
        {
            getline(ss,temp);
            istringstream(temp) >> releaseYear;
            Movie newMovie = Movie("F", stock,director,title,releaseYear);
            inv.insert(newMovie);
        }
        else if(movieType == "D")
        {
            getline(ss,temp);
            istringstream(temp) >> releaseYear;
            Movie newMovie = Movie("D", stock,director,title,releaseYear);
            inv.insert(newMovie);
        }
        else 
        {
            cout << "Error: Invalid Movie Type." << endl; 
        }
        
    } 
}

void Store::processTransactions(ifstream &infile3)
{
    string line;

    cout << "process method" << endl;
    while (getline(infile3, line))
    {
        stringstream ss(line);
        string temp;
        string commandType, mediaType, movieType, movieTitle, directorName, majorActor;
        int customerID, releaseYear, releaseMonth;
        getline(ss, commandType, ' ');
        if(commandType == "I"){
            displayInventory();
        }else if(commandType == "H"){
            getline(ss, temp, ' ');
            stringstream(temp) >> customerID;
            if(table.hasCustomer(customerID) == false)
            {
            cout << "ERROR: No customer with this ID found." << endl;
            }else{
                string name = table.getCustomer(customerID).getFirstName() + " " + table.getCustomer(customerID).getLastName();
                inv.printCustomerHistory(customerID, name);
            }
        }else if(commandType == "B" || commandType == "R"){
            getline(ss, temp, ' ');
            istringstream(temp) >> customerID;
            if(table.hasCustomer(customerID) == false)
            {
            cout << "ERROR: No customer with this ID found." << endl;
            } 

            getline(ss, mediaType, ' ');
            if(mediaType != "D")
            {
            cout << "ERROR: Invalid Media Type." << endl;
            }
            getline(ss, movieType, ' ');
            if(movieType == "F"){
                getline(ss, movieTitle, ',');
                getline(ss,temp);
                istringstream(temp) >> releaseYear;
                string author = "";
                for(int i = 0; i < inv.comedies.size();i++){
                    if(" " + movieTitle == inv.comedies.at(i).getTitle()){
                        author = inv.comedies.at(i).getDirector();
                    }
                }

                if(commandType == "B"){
                    inv.ComedyMethod("B", " " + movieTitle, releaseYear);
                    inv.customerHistoryAdd(customerID, "B", author, movieTitle);
                }else if(commandType == "R"){
                    inv.ComedyMethod("R", " " + movieTitle, releaseYear);
                    inv.customerHistoryAdd(customerID, "R", author, movieTitle);
                }
            }else if(movieType == "D"){
                getline(ss,directorName,',');
                getline(ss,movieTitle,',');
                istringstream(temp) >> releaseYear;

                if(commandType == "B"){
                    inv.DramaMethod("B", " " + directorName, movieTitle);
                    inv.customerHistoryAdd(customerID, "B", directorName, movieTitle);
                }else if(commandType == "R"){
                    inv.DramaMethod("D", " " + directorName, movieTitle);
                    inv.customerHistoryAdd(customerID, "R", directorName, movieTitle);
                }

            }else if(movieType == "C"){
                getline(ss, temp, ' ');
                istringstream(temp) >> releaseMonth;
                getline(ss, temp, ' ');
                istringstream(temp) >> releaseYear;
                getline(ss, majorActor, ' ');

                string author = "";
                string theTitle = "";
                for(int i = 0; i < inv.classics.size();i++){
                    if(majorActor == inv.classics.at(i).majorActor && releaseMonth == inv.classics.at(i).month && releaseYear == inv.classics.at(i).year){
                        author = inv.classics.at(i).getDirector();
                        theTitle = inv.classics.at(i).getTitle();
                    }
                }

                if(commandType == "B"){
                    inv.ClassicMethod("B", releaseMonth, releaseYear, majorActor);
                    inv.customerHistoryAdd(customerID, "B", author, theTitle);
                }else if(commandType == "R"){
                    inv.ClassicMethod("R", releaseMonth, releaseYear, majorActor);
                    inv.customerHistoryAdd(customerID, "R", author, theTitle);
                }
                 
            }else{
                cout << "ERROR: " << movieType <<" Invalid Transaction Type. Try Again." << endl;
            }
        }else{
            cout << "ERROR: Invalid command type." << endl;
        }
    }
}

void Store::displayInventory()
{
    if (inv.isEmpty() == false)
    {
        inv.display();
        cout << endl;
    }
}

bool Store::addCustomer(Customer customer)
{
    table.addCustomer(customer);
    return true;

}