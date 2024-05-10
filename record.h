/*****************************************************************
//  NAME:        Michaella Villanueva
//
//  HOMEWORK:    project2
// 
//  CLASS:       ICS 212
// 
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27, 2023
//
//  FILE:        record.h
//
//  DESCRIPTION:
//   Describe the file
//
****************************************************************/

#ifndef RECORD_H
#define RECORD_H
struct record
{
    int accountno;
    char name[30];
    char address[50];
    struct record* next;
};
#endif
