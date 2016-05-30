//
//  Log.h        CLASS DECLATIONS
//  Programming Project 2
//
//  Created by Andres Quinones on 11/12/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#ifndef __Programming_Project_2__Log__
#define __Programming_Project_2__Log__

#include <stdio.h>

class Log
{
private:
    int bookID, memberID, issueD, dueD;     // each log has 4 items. BookID MemberID issueDate DueDate
public:
    Log();                                  // empty constructor
    Log(int b, int m, int i, int d);        // all items constructor. for making easier to make a log when program has data for each item
    int getBookID();                        // getters for each item
    int getMemberID();
    int getIssueD();
    int getDueD();
    void setBookID(int b);                  // setters for each item
    void setMemberID(int m);
    void setIssueD(int i);
    void setDueD(int d);
};
#endif /* defined(__Programming_Project_2__Log__) */
