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
//  FILE:        driver.cpp
//
//  DESCRIPTION:
//        This file is used to test the extra credit constructor,
//        overloaded operator= method and overloaded operator<<
//        method. 
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
//  DESCRIPTION:   The main function is to test the extra credit
//                 methods: the copy constructor, an overloaded
//                 operator = method, and an overloaded operator
//                 << method.
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
    //testing the copy constructor
    llist listA("testcase.txt");
    listA.addRecord(1000, "Im Nayeon", "NayeonWorld");
    listA.addRecord(2000, "Yoo Jeongyeon", "JeongyeonWorld");
    listA.addRecord(3000, "Momo Hirai", "MomoWorld");
    listA.addRecord(4000, "Sana Minatozaki", "SanaWorld");
    llist listB(listA);

    //testing overloaded << operator
    cout << "\n\n======= Testing the copy constructor.(list listB(listA) =======\n";
    cout << "\n===========================listA=========================== \n";
    cout << listA;
  
    cout << "===========================listB=========================== \n";
    cout << listB;

    //testing the overloaded = operator
    llist listC;
    listC.addRecord(5000, "Park Jihyo", "JihyoWorld");
    listC.addRecord(6000, "Mina Myoui", "MinaWorld");
    listC.addRecord(7000, "Kim Dahyun", "DahyunWorld");
    listC.addRecord(8000, "Son Chaeyoung", "ChaeWorld");
    listC.addRecord(5000, "Tzuyu Chou", "TzuyuWorld");
    listA = listC;

    //testing the overloaded << operator
    cout << "\n\n======= Testing the overloaded = operator. (listA = listC) =======\n";
    cout << "\n===========================listC===========================\n";
    cout << listC;
    cout << "===========================listA===========================\n\n";
    cout << listA;

    return 0;
}
