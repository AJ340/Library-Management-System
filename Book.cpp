//
//  Book.cpp
//  Programming Project 2   CLASS DEFINITIONS
//
//  Created by Andres Quinones on 11/12/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#include "Book.h"
#include <string>

Book::Book(int i, string t, string a, string cat, int c)
{
    id=i;
    copies=c;
    title=t;
    author=a;
    category=cat;
}

Book::Book()
{}

int Book::getId()           //getters
{
    return id;
}
int Book::getCopies()
{
    return copies;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

string Book::getCategory()
{
    return category;
}

void Book::setId(int i)         //setters
{
    id=i;
}

void Book::setCopies(int c)
{
    copies=c;
}

void Book::setTitle(string t)
{
    title=t;
}

void Book::setAuthor(string a)
{
    author=a;
}
void Book::setCategory(string cat)
{
    category=cat;
}