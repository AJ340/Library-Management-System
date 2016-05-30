//
//  Book.h  CLASS DECLARATIONS
//  Programming Project 2
//
//  Created by Andres Quinones on 11/12/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#ifndef __Programming_Project_2__Book__
#define __Programming_Project_2__Book__

#include <stdio.h>
#include <string>
using namespace std;
class Book
{
private:
    int id, copies;
    string title,author,category;                       // each line in book.txt has ID TITLE AUTHOR CATEGORY COPIES
public:
    Book();                                                 // empty constructor
    Book(int i, string t, string a, string cat, int c);     // constructor that sets each item. (easy to make a book when program has data for each item)
    int getId();                                            //getters
    int getCopies();
    string getTitle();
    string getAuthor();
    string getCategory();
    void setId(int i);                                      //setters
    void setCopies(int c);
    void setTitle(string t);
    void setAuthor(string a);
    void setCategory(string cat);
};
#endif /* defined(__Programming_Project_2__Book__) */
