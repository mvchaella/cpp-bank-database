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
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:
//        This program is the user interface of a banks database
//        and allows the user to add a new customers account, 
//        which consists of their name, account number, and 
//        their address.It also allows the user to remove an 
//        account, find an account, and print the accounts. 
//
****************************************************************/

#include <cstring>
#include <iostream>
using namespace std;

#include "record.h"
#include "llist.h"

/****************************************************************
//
//  Function name: main
//  
//  DESCRIPTION:   The main function checks to see if the command
//                 line arguments specifies for debugmode to be
//                 turned on, and if so turns on debugmode. It
//                 calls the menu function that also has all the
//                 user options.The menu function prints out the 
//                 prompts for the user to follow in order to 
//                 modify the database. It sends the information 
//                 gathered to the database.
//                 
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : successful
// 
****************************************************************/

int main(int argc, char* argv[])
{
    int isopen = 1;
    char input[10];
    int len;

    int accountnum;
    char name[30];
    char address[50];

    int addResult;
    int findResult;
    int deleteResult;

    llist database("data.txt");
    llist copy(database); 

    #ifdef DEBUG
    cout << "\n================================================\n";
    cout << "    Function: main\n";
    cout << "    Parameters: \n";
    cout << "        struct record **: " << endl;
    cout << "        int accountno: " << accountnum << endl;
    cout << "        char[] name: " << name << endl;
    cout << "        char[] address: " <<  address << endl;
    cout << "================================================\n";
    #endif

    cout << "\nWelcome to the main menu of the UH Bank database."
    << " The following commands will allow you to access or "
    << "modify an existing customer's bank records or to create "
    << "a new account. Type in a command to proceed.\n\n";
    do
    {
        cout << "\n    Commands: \n";
        cout << "            add: to add a new record in the database\n";
        cout << "            printall: to print all records in the database\n";
        cout << "            find: to find the record of an account number\n";
        cout << "            delete: to delete an existing record\n";
        cout << "\n";
        cout << "\nEnter an option or type 'quit' to exit: ";
        cin.getline(input, 10);
        len = strlen(input);
        if (strncmp(input, "add", len) == 0)
        {
            cout << "To add an account please follow the following prompts.\n";
            cout << "Enter Account #: ";
            while (!(cin >> accountnum) || accountnum <= 0)
            {
                cout << "Invalid input error. ";
                cout << "Please enter your account number again.\n";
                cin.clear();
                cin.ignore();
                cout << "Enter Account #: ";
            }
            cin.clear();
            cin.ignore();
            cout << "Name: ";
            cin.getline(name, 30);
            cout << "Please enter your address below. ";
            cout << "Type '!' when you're done and click enter.\n";
            cout << "Address: ";
            cin.getline(address, 50, '!');
            cin.clear();
            cin.ignore();
            addResult = database.addRecord(accountnum, name, address);
            if (addResult == 0)
            {
                cout << "Account was added successfully.\n";
            }
            else
            {
                cout << "Account could not be added. "
                     << "Please check the account number and try again.\n";
            }
        }
        else if (strncmp(input, "printall", len) == 0)
        {
            //database.printAllRecords();
            cout << database;
        }
        else if (strncmp(input, "find", len) == 0)
        {
            cout << "\nTo find an account please follow the following prompts.\n";
            cout << "Enter Account #: ";
            while (!(cin >> accountnum) || accountnum <= 0)
            {
                cout << "Invalid input error. "
                     << "Please enter your account number again.\n";
                cin.clear();
                cin.ignore();
                cout << "Enter Account #: ";
            }
            cin.clear();
            cin.ignore();
            findResult = database.findRecord(accountnum);
            if (findResult == -1)
            {
                cout << "Account could not be found.\n";
            }
        }
        else if (strncmp(input, "delete", len) == 0)
        {
            cout << "\nTo delete an account please follow the following prompts.\n";
            cout << "Enter Account #: ";
            while (!(cin >> accountnum) || accountnum <= 0)
            {
                cout << "Invalid input error. "
                     << "Please enter your account number again.\n";
                cin.clear();
                cin.ignore();
                cout << "Enter Account #: ";
            }
            cout << "Inputed Account #: " << accountnum << endl;
            cin.clear();
            cin.ignore();
            deleteResult = database.deleteRecord(accountnum);
            if (deleteResult == -1)
            {
                cout << "Account could not be found.\n";
            }
            else
            {
                cout << "Account has been successfully deleted.\n";
            }
        }
        else if (strncmp(input, "quit", len) == 0)
        {
            cout << "\nExiting database. Have a good day.\n\n";
            isopen = 0;
        }
        else
        {
            cout << "Invalid Input.\n";
        }
    }
    while (isopen);
}


