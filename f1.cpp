/*
* FILE : m4.cpp
* PROJECT : SENG1000 - Major Assignment #4
* PROGRAMMER : Ayushkumar Bhupatbhai Rakholiya
* FIRST VERSION : 2024-04-1
* DESCRIPTION :
*   This program will takes in 10 pair of information about flights and stores the destination and 
date in an array of structs and displayed it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#pragma warning (disable: 4996)

typedef struct {
    char* destination;
    char* date;
} FlightInfo;
