//
//  Log.cpp
//  Programming Project 2   CLASS DEFINITIONS
//
//  Created by Andres Quinones on 11/12/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#include "Log.h"

Log::Log()
{}

Log::Log(int b, int m, int i, int d)
{
    bookID=b;                   
    memberID=m;
    issueD=i;
    dueD=d;
}

int Log::getBookID()            // getters for each item
{
    return bookID;
}

int Log::getMemberID()
{
    return memberID;
}

int Log::getIssueD()
{
    return issueD;
}

int Log::getDueD()
{
    return dueD;
}
void Log::setBookID(int b)      //setters for each item
{
    bookID=b;
}

void Log::setMemberID(int m)
{
    memberID=m;
}

void Log::setIssueD(int i)
{
    issueD=i;
}

void Log::setDueD(int d)
{
    dueD=d;
}