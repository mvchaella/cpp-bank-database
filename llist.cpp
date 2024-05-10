/*****************************************************************
//
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
//  FILE:        llist.cpp
// 
//  DESCRIPTION:
//   This file contains all the function definitions for all the
//   llist class member functions. This holds all the information
//   given by the users, and it performs several actions such as
//   adding records, printing all the record, finding record,
//   and deleting record
// 
*****************************************************************/

#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

#include "record.h"
#include "llist.h"

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   This constructor initializes the object with 
//                 a start value of NULL. 
//
//  Parameters:     none
//                 
//  Return values:  none
//                 
*****************************************************************/

llist::llist()
{
    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    Constructor: llist() " << endl;
    cout << "================================================\n";
    #endif
    start = NULL;
}

/*****************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   A constructor that initializes the object with
//                 start = NULL and calling readfile to retrieve
//                 information already stored
//
//  Parameters:    filename (char[]) : the name of the file
//                
//  Return values:  none
// 
*****************************************************************/

llist::llist(char filename[])
{
    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    Constructor llist()\n";
    cout << "    Parameters: \n";
    cout << "        char[] filename: " << filename << endl;
    cout << "================================================\n";
    #endif
    start = NULL;
    readfile();
}

/*****************************************************************
//
//  Function name: llist
// 
//  DESCRIPTION:   EXTRA CREDIT: This constructor copies an object
//                 to another object
//
//  Parameters:    original (llist&): the object to copy
//                 
//  Return values:  none
//                 
*****************************************************************/

llist::llist(const llist& original)
{ 
    struct record * temp;
    struct record * current;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    Constructor: llist() " << endl;
    cout << "    Parameters: \n";
    cout << "        original (const llist&) " << endl;
    cout << "================================================\n";
    #endif
    
    if (original.start == NULL)
    {
        this->start = NULL;
    }
    else
    {
        current = original.start;
        this->start = new record;
        this->start->accountno = current->accountno;
        strcpy(this->start->name, current->name);
        strcpy(this->start->address, current->address);
        this->start->next = NULL;
        
        temp = this->start;
        current = current->next;

        while (current != NULL)
        {
            temp->next = new record;
            temp = temp->next;
            temp->accountno = current->accountno;
            strcpy(temp->name, current->name);
            strcpy(temp->address, current->address);           
            temp->next = NULL;
            current = current->next;
        } 
    } 
}

/*****************************************************************
//
//  Function name: opererator=
//  
//  DESCRIPTION:   EXTRA CREDIT: This is an overloaded assignment
//                 operator that copies an object to another 
//                 object
//
//  Parameters:    original (llist&): the object to copy
//                 
//  Return values:  llist&
//                  
*****************************************************************/

llist& llist::operator=(const llist& original)
{
    struct record * temp;
    struct record * current;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    Function: operator= " << endl;
    cout << "    Parameters: \n";
    cout << "        original (const llist&) " << endl;
    cout << "================================================\n";
    #endif

    if (original.start == NULL)
    {
        this->start = NULL;
    }
    else
    {
        current = original.start;
        this->start = new record;
        this->start->accountno = current->accountno;
        strcpy(this->start->name, current->name);
        strcpy(this->start->address, current->address);
        this->start->next = NULL;

        temp = this->start;
        current = current->next;

        while (current != NULL)
        {
            temp->next = new record;
            temp = temp->next;
            temp->accountno = current->accountno;
            strcpy(temp->name, current->name);
            strcpy(temp->address, current->address);
            temp->next = NULL;
            current = current->next;
        }
    }
    return *this;
}

/*****************************************************************
//
//  Function name: ~llist
// 
//  DESCRIPTION:   A destructor that calls writefile funciton
//                 and cleanup function.
//
//  Parameters:    none
//      
//  Return values: none
// 
*****************************************************************/

llist::~llist()
{
    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    Destructor: ~llist() " << endl;
    cout << "================================================\n";
    #endif
    writefile();
    cleanup();
}

/*****************************************************************
//
//  Function name: addRecord
// 
//  DESCRIPTION:   The addRecord() function takes the user's
//                 information and stores it in a struct record.
//                 It is then added to a linked list which is 
//                 in ascending order based on account number.
// 
//  Parameters:    uaccountno (int) : the account number
//                 uname (char*) : an array of characters
//                                representing the name
//                 uaddress (int) : an array of characters
//                                  representing the address
//
//  Return values: result (int): 0: succesfful insertion
//                             -1: unsucessful insertion
//  
******************************************************************/

int llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    int result = -1;
    struct record * current = start;
    struct record * temp = NULL;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    llist method: addRecord\n";
    cout << "    Parameters: \n";
    cout << "        int uaccountno: " << uaccountno << endl;
    cout << "        char[] uname: " << uname << endl;
    cout << "        char[] uaddress: " <<  uaddress << endl;
    cout << "================================================\n";
    #endif

    temp = new record;
    temp->accountno = uaccountno;
    strcpy(temp->name, uname);
    strcpy(temp->address, uaddress);
    temp->next = NULL;

    if (start == NULL || start->accountno < uaccountno)
    {
        temp->next = start;
        start = temp;
        result = 0;
    }
    else
    {
        while (current->next != NULL && uaccountno < current->next->accountno)
        {
            current = current->next;
        }
        if (current->next != NULL && uaccountno == current->next->accountno)
        {
            delete temp;
            result = -1;
        }
        else
        {
            temp->next = current->next;
            current->next = temp;
            result = 0;
        }
    }
    return result;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   The printAllRecords() function prints all the 
//                 struct records that are stored in the database.
// 
//  Parameters:    none
//                                          
//  Return values: void
//  
******************************************************************/

void llist::printAllRecords()
{
    struct record * current = start;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    llist method: printAllRecord() " << endl;
    cout << "================================================\n";
    #endif

    while (current != NULL)
    {
        cout << "\nAccount #: " << current->accountno << endl;
        cout << "Name: " << current->name << endl;
        cout << "Address: " << current->address << endl;
        current = current->next;
    }
}

/*****************************************************************
//
//  Function name: opererator<<
//   
//  DESCRIPTION:   EXTRA CREDIT: This is an overloaded assignment
//                 operator that copies an object to another 
//                 object
//
//  Parameters:    original (llist&): the object to copy
//                 
//  Return values: end ostream&
//                  
*****************************************************************/

ostream& operator<<(ostream& out, const llist& list)
{
    struct record * current = list.start;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    Function: operator<< " << endl;
    cout << "    Parameters: \n";
    cout << "        out (oustream&) " << endl;
    cout << "        list (const llist&) " << endl;
    cout << "================================================\n";
    #endif

    while (current != NULL)
    {
        cout << "\nAccount #: " << current->accountno << endl;
        cout << "Name: " << current->name << endl;
        cout << "Address: " << current->address << endl;
        current = current->next;
    }

    return out;
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   The findRecord() function takes the inputted
//                 account number and prints the record information.
//                  
//  Parameters:    uaccountnum (int): the account number
//                                        
//  Return values: result (int): 0: successful search
//                              -1: unsucessful search
//   
******************************************************************/

int llist::findRecord(int uaccountno)
{
    int result = -1;
    struct record * current = start;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    llist method: findRecord\n";
    cout << "    Parameters: \n";
    cout << "        int uaccountno: " << uaccountno << endl;
    cout << "================================================\n";
    #endif

    if (start == NULL)
    {
        result = -1;
    }
    else
    {
        while (current != NULL && result == -1)
        {
            if (current->accountno == uaccountno)
            {
                cout << "\nAccount #: " << current->accountno;
                cout << "\nName: " << current->name;
                cout << "\nAddress: " << current->address << endl;
                result = 0;
            }
            current = current->next;
        }
    }

    return result;
}

/*****************************************************************
//
//  Function name: deleteRecord
// 
//  DESCRIPTION:   The deleteRecord function takes the inputted 
//                 user's account number and removes the record
//                 from the linked list.
//
//  Parameters:    uaccountno (int) : the account number
//                  
//  Return values: result (int): 0: succesfful deletion
//                              -1: unsucessful deletion
//
******************************************************************/

int llist::deleteRecord(int uaccountno)
{
    int result = -1;
    struct record * current = start;
    struct record * before_current = NULL;
    struct record * temp;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    llist method: deleteRecord\n";
    cout << "    Parameters: \n";
    cout << "        int uaccountno: " << uaccountno << endl;
    cout << "================================================\n";
    #endif

    if (start == NULL)
    {
        result = -1;
    }
    else
    {
        if (current->accountno == uaccountno)
        {
            temp = current->next;
            delete current;
            start = temp;
            result = 0;
        }
        else
        {
            while (current->next != NULL && uaccountno < current->accountno)
            {
                before_current = current;
                current = current->next;
            }
            if (uaccountno == current->accountno)
            {
                temp = current->next;
                delete current;
                before_current->next = temp;
                result = 0;
            }
        }
    }
    return result;
}

/*****************************************************************
//
//  Function name: readfile
// 
//  DESCRIPTION:   The readfile() function reads the records
//                 that are currently in the file into a linked
//                 list.
//
//  Parameters:    none
//                
//  Return values:  0 : successful read
//                 -1 : unsuccessful read
// 
*****************************************************************/

int llist::readfile()
{
    int result = -1;
    int faccountno;
    char fname[30];
    char faddress[50];

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    llist method: readfile() " << endl;
    cout << "================================================\n";
    #endif

    ifstream file("data.txt");
    if (file.is_open())
    {
        while (file >> faccountno)
        {
            file.ignore();
            file.getline(fname, 30);
            file.getline(faddress, 50, '@');
            addRecord(faccountno, fname, faddress);
            file.clear();
        }
        file.close();
        result = 0;
    }
    return result;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   The writefile() function writes the records
//                 that are currently in the linked list into
//                 a file.                 
//  
//  Parameters:    none
//                
//  Return values:  0 : successful write
//                  -1 : unsuccessful write
// 
*****************************************************************/

int llist::writefile()
{
    int result = -1;
    struct record * current = start;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    llist method: writefile() " << endl;
    cout << "================================================\n";
    #endif

    ofstream file("data.txt");
    if (file.is_open())
    {
        while (current != NULL)
        {
            file <<  current->accountno << endl;
            file <<  current->name << endl;
            file << current->address;
            file << "@" << endl;
            current = current->next;
        }
        file.close();
        result = 0;
    }
    return result;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   The cleanup() function frees all the heap space
//                 that was used during the runtime of the program.
//
//  Parameters:    none
//                                       
//  Return values: void
//    
******************************************************************/

void llist::cleanup()
{
    struct record * current = start;
    struct record * temp = NULL;

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    llist method: cleanup() " << endl;
    cout << "================================================\n\n";
    #endif

    while (current != NULL)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
}
