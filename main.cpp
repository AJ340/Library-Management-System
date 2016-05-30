//
//  main.cpp
//  Programming Project 2
//
//  Created by Andres Quinones on 11/12/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "Book.h"
#include "Log.h"
using namespace std;

void makeSpaceSep(string &a)  // changes any underscores in passed string to spaces
{
    replace(a.begin(), a.end(), '_', ' ');
}

void makeUndScoSep(string &a) // changes any spaces in passed string to underscores
{
    replace(a.begin(), a.end(), ' ', '_');
}

int search(Book a, vector<Book> b)  // searches a vector of books for matching book
{
    for(int i=0;i<b.size();i++)
    {
        if(a.getTitle()==b[i].getTitle() && a.getAuthor()==b[i].getAuthor())  // if matching book title and author is found compare category of book with category of match in vector
        {
            if(a.getCategory()==b[i].getCategory() && a.getCategory()==b[i].getCategory())
                return i;           //returns position where book author, title and category matches
            else
                return -2;          //if title && author matches but category doesnt returns -1
        }
    }
    return -1;                      // if book title and author match isnt found in vector of books, -1 is returned
}

int getPos(int id,vector<Book> a)   // searches for a book ID in a vector of books. returns a position in vector if ID is found
{
    for(int i=0;i<a.size();i++)
    {
        if(id==a[i].getId())
        {
            return i;
        }
    }
    return -1;                      //returns -1 if it isnt found
}

void changeOldID(vector<Log> &a, int oldBookID, int newBookID)  //Bonus Point Assignment: Searches for an old bookID in the Logs vector and if its found change it to the newBookID
{
    for (int i=0; i<a.size(); i++)
        if(oldBookID==a[i].getBookID())
            a[i].setBookID(newBookID);
}

void readFiles(vector<Book> &b, vector<Log> &c)                 //function used to read book.txt and circulation.txt
{                                                               // stores data from books.txt in a vector of books and circulation.txt in vector of logs
    int id, copies;

    ifstream inBooksFile;
    inBooksFile.open("books.txt");
    if (inBooksFile.fail())
    {
        cout << "Error reading books.txt" << endl;             // if opening of file fails prints error and exits program
        exit(1);
    }
    while (inBooksFile >> id)
    {
        string title,author,category;
        inBooksFile >>title >>author >>category >>copies;
            makeSpaceSep(title);                                //books.txt has strings with underscores. Calls function to replace them w/ spaces
            makeSpaceSep(author);                               // **  does the same thing for the title, author and category of books
            makeSpaceSep(category);
            Book a(id,title,author,category,copies);
            b.push_back(a);
        //inBooksFile.
    }
    inBooksFile.close();
    
    cout << "books.txt successfully read!" << endl;

    int bookID, memberID, issueD, dueD;

    ifstream inLogsFile;
    inLogsFile.open("circulation.txt");
    if (inLogsFile.fail())
    {
        cout << "Error reading circulation.txt";              // if opening of file fails prints error and exits program
        exit(1);
    }
    while (inLogsFile >> bookID)
    {
        inLogsFile >>memberID >>issueD >>dueD;
        Log a(bookID, memberID, issueD, dueD);
        c.push_back(a);
    }
    inLogsFile.close();
    cout << "circulation.txt successfully read!" << endl;

}

void writeFiles(vector<Book> &b, vector<Log> &l)             // function used to write data from vectors back to books.txt and circulation.txt
{
    ofstream outBooks;
    outBooks.open("books.txt");
    if (outBooks.fail())
    {
        cout << "Error opening books.txt";                   //if fails to open file for writel. error is printed and exits.
        exit(1);
    }
    else
    {
        for(int i=0;i<b.size();i++)
        {
            string cat,aut,titl;
            cat = b[i].getCategory();
            makeUndScoSep(cat);                             // vector has strings with spaces. we want them with underscores instead because spaces are delimiters in .txt file
            aut = b[i].getAuthor();
            makeUndScoSep(aut);
            titl = b[i].getTitle();
            makeUndScoSep(titl);
            outBooks << b[i].getId() << " " << titl << " "<< aut << " "<< cat << " "<< b[i].getCopies() << " \n";
        }
        cout << "books.txt successfully written to." << endl;
    }
        outBooks.close();
    
    ofstream outLogs;
    outLogs.open("circulation.txt");
    if (outLogs.fail())
    {
        cout << "Error opening circulation.txt";            //terminate program if error opening file for write
        exit(1);
    }
    else
    {
        for(int i=0;i<l.size();i++)
        {

            outLogs << l[i].getBookID() << " " << l[i].getMemberID() << " "<< l[i].getIssueD() << " "<< l[i].getDueD() << endl;
        }
        cout << "circulation.txt successfully written to." << endl;
    }
    outLogs.close();
}



void editBookDet(Book &bunch)                         //function to edit a book's details. Used to avoid clutter in main function.
{
    int choice;
    cout << "What would you like to change?" << endl                    //prompts user to choose what they want to change and gets new values and changes data in book
    << "Options: 0 for ID, 1 for Title, 2 for Author, 3 for Category, 4 for number of copies.";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    switch(choice)
    {
        case 0:
        {
            int change;
            cout << "Enter the new ID:";
            cin >> change;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            bunch.setId(change);
            break;
        }
        case 1:
        {
            string change;
            cout << "Enter the new Title:";
            getline(cin,change);
            bunch.setTitle(change);
            break;
        }
        case 2:
        {
            string change;
            cout << "Enter the new Author:";
            getline(cin,change);
            bunch.setAuthor(change);
            break;
        }
        case 3:
        {
            string change;
            cout << "Enter the new Category:";
            getline(cin,change);
            bunch.setCategory(change);
            break;
        }
        case 4:
        {
            int change;
            cout << "Enter the new nuber of copies:";
            cin >> change;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            bunch.setCopies(change);
            break;
        }
        default:
            cout << choice << " is not a valid option." << endl;
    }
    cout << "Change successfully made." << endl;
}

void printBooks(vector<Book> &a)                        //function used to print the data of a bunch of books stored in a vector
{
    for(int i=0;i<a.size();i++)
    {
            cout << a[i].getTitle() << " by " << a[i].getAuthor()<< endl
            << "Book ID: " << a[i].getId() << "  Category: " << a[i].getCategory() << endl << endl;
    }
}

int main()
{
    vector<Book> collection;
    vector<Log> circulation;
    readFiles(collection, circulation);     //reads info in books.txt and stores it in collection vector. reads circulation.txt and stores it in circulation vector
    int choice;
    bool x=true;
    
    
    time_t t = time(0);   // get current time in time_t struct format
    struct tm * now = localtime( & t ); //convert it to a more useful format
    int currYear = now->tm_year + 1900; //Extract year
    int currMonth = now->tm_mon + 1; //Extract month
    int currDay = now->tm_mday; //Extract daybreak;
    int currDate = currYear;
    currDate = currDate*100 + currMonth;
    currDate = currDate*100 + currDay;
    
    while(x)
    {
        cout << "What would you like to do?" << endl            // main menu
            << "    Enter 1 to add a book to collection." << endl
            << "    Enter 2 to edit collection books' details" << endl
            << "    Enter 3 to get a list of books borrowed by a member." << endl
            << "    Enter 4 to get a list of overdue books." << endl
            << "    Enter 0 to save and exit" << endl;

        cin >> choice;
        switch (choice)
        {
            case(1):                    // add a book to collection option
            {
                int id, copies;
                string title,author,category;
                
                cout << "What is the book's ID number?" << endl;        //get book id
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');     //online solution fixes error with getline on next cin operation. clears buffer to prepare for following cin
                cout << "What is the book's title?" << endl;
                getline(cin,title);                                     //get book title
                cout << "Who is the author of the book(s)?" << endl;
                getline(cin,author);                                    //get book author
                cout << "What is the category of the book?" << endl;
                getline(cin,category);                                  //get book category
                cout << "How many copies are you adding?" << endl;
                cin >> copies;                                          // get book copies
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                
                Book newBook(id,title,author,category,copies);          // make book using gathered info
                int pos=search(newBook, collection);                    // returns position if newbook exists in collection. -1 if doesnt exist and -2 if title&&author match but category doesnt match an item in collection
                if(pos==(-1))
                {
                    collection.push_back(newBook);                      //if book doesnt exist in collection. add book to end of collection
                    cout << "Book added to collection!"<< endl;
                }
                if(pos>=0)                                              // if it does exist. add the number of copies to the number of copies already in collection.
                {
                    cout << "Book found in collection. Adding " << copies << " copies." << endl;
                    collection[pos].setCopies(collection[pos].getCopies()+copies);
                }
                if(pos==-2)                                             // print out error and take no action if category doesnt match.
                    cout << "Error: Category of book doesnt match category in collection." << endl;
                break;                                                  // break to main menu after action.
            }
            case(2):                        //edit a book's details option
            {
                int bookID,pos=-1;          //
                bool x=true;                // x will be used to continue making changes later
                char cont;

                cout<< "Enter the ID of the book:";     //get ID of book to edit
                cin >> bookID;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                
                pos=getPos(bookID, collection);         //search collection for book
                if (pos >=0)                            // if exists in collection...
                {
                    cout<< collection[pos].getTitle() << " found in collection.";
                    while(x)
                    {
                        int oldBID =collection[pos].getId();        //track book ID before changes
                        editBookDet(collection[pos]);               // call function to make changes to a book
                        int newBID = collection[pos].getId();       // store new book ID after changes
                        if(oldBID != newBID)                        // if ID was changed
                            changeOldID(circulation,oldBID,newBID);     // change instances of the old id in circulation vector to the new ID number
                        cout<<"Would you like to change another field?(y/n)";   // ask if user wants to make more changes
                        cin >> cont;
                        if (cont=='n' || cont=='N')                 // if user wants to make another change while loops again. if not change x to false. thus terminating the loop after this cycle.
                            x=false;
                    }
                    if (collection[pos].getCopies()==0)             // checks the number of copies of the book working with. if its 0 it is deleted from the vector collection
                    {
                        cout<< "Updated to 0 copies. Deleting book."<<endl;
                        collection.erase(collection.begin()+pos);
                    }
                }
                else
                    cout << "That BookID wasn't found in the collection."<< endl;       // if book id entered isnt found in collection then print error and break to main menu
                cout << endl;
                break;
            }
            case(3):        // option to print the books a member has currently borrowed.
            {
                int memID,pos;
                bool found=0, currHasBook=0;
                vector<Book> borrowed;
                cout << "Enter the member's ID number:";
                cin >> memID;                           // get member id to search logs for
                
                for(int i=0;i<circulation.size();i++)
                {
                    if(memID==circulation[i].getMemberID())         // check logs for member id. if found continue
                    {
                        found=1;                                    // set found flag to true. if found was set to true then the member has borrowed books.
                            int bookID;
                            bookID=circulation[i].getBookID();      //get book id of log with member id
                            pos=getPos(bookID, collection);         // get position of book id in collection
                            if (pos>=0)
                                borrowed.push_back(collection[pos]);    // push the book at the position of the collection to the borrowed vector.
                    }
                }
                if(found)   // if borrowed has items print list of books borrowed by member
                {
                    cout << "Heres a list of books borrowed by member with ID " << memID << ":" << endl;
                    printBooks(borrowed);
                }
                if(!found) // if borrowed doesnt have items. prompt that id wasnt found in circulation
                    cout << "That member ID was not found in circulation.txt:" << endl;
                break;
            }
            case(4):
            {
                int bookID,pos;
                vector<Book> overdue;
    
                for(int i=0;i<circulation.size();i++)
                {
                    if(circulation[i].getIssueD()< currDate && currDate <circulation[i].getDueD()) // if issue date < current date < due date then...
                    {
                        bookID = circulation[i].getBookID();                    // get the book ID on that log
                        pos=getPos(bookID, collection);                         // get position in collection that has that book id
                        if (pos>=0)
                            overdue.push_back(collection[pos]);                 //add the book with that ID to overdue books vector
                    }
                }
            
                if (overdue.size()>0)                                       // if there are overdue books
                {
                    cout << "Heres a list of overdue books:"  << endl;              // print books in overdue vector
                    printBooks(overdue);
                }
                else                                                        // otherwise. print there are none
                    cout << "There are no overdue books." << endl;
            }
                break;
            case(0):                    // save and quit option
            {
                writeFiles(collection, circulation);        // dumps all the data in circulation and collection vectors into circulation.txt and collection.txt
                x=0;                                        // x set to 0 thus terminating main menu loop on next iteration of while statement
                break;                                      //
            }
            default:
                cout << "That is not a valid option" << endl;           // if any option other than 0,1,2,3,4 are entered then print error and ask to perform another option
        }
    }
    return 0;
}


