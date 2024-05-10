/*****************************************************************
//  NAME:        Michaella Villanueva
//
//  HOMEWORK:    Project 2
// 
//  CLASS:       ICS 212
// 
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27, 2023
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This file contains the llist class and its function protoypes.
//
*****************************************************************/

#ifndef LLIST_H
#define LLIST_H
class llist
{
    private:
        record *    start;
        char        filename[20];
        int         readfile();
        int         writefile();
        void        cleanup();

    public:
        llist();
        llist(char[]);
        llist(const llist&);
        llist& operator=(const llist&);
        ~llist();
        int addRecord(int, char [ ], char [ ]);
        int findRecord(int);
        void printAllRecords();
        int deleteRecord(int);
        friend std::ostream& operator<<(std::ostream& out, const llist& list);
};
#endif
