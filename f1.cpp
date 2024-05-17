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

// data types
typedef struct {
    char* destination;
    char* date;
} FlightInfo;


// prototypes
void fillFlightInfo(FlightInfo* flightInfo, char* destination, char* date);
void printFlightInfo(FlightInfo* flightInfo);


int main() {

    // 10 size array of FlightInfo struct
    FlightInfo flightInfo[10];

    // for loop to get destination & date information from user
    for (int i = 0; i < 10; i++) {
        char destination[30] = { 0 };
        char date[30] = { 0 };

        printf("Enter name of destination %d: ", i + 1);
        fgets(destination, sizeof(destination), stdin);
        destination[strcspn(destination, "\n")] = '\0';

        printf("Enter date of flight %d: ", i + 1);
        fgets(date, sizeof(date), stdin);
        date[strcspn(date, "\n")] = '\0';

        // call the function to fill the struct with user input
        fillFlightInfo(&flightInfo[i], destination, date);
    }

    // call the function to print the flight data get from user
    printFlightInfo(flightInfo);

    //free the data which is allocated
    free(flightInfo->destination);
    free(flightInfo->date);

    return 0;
}

//
// FUNCTION : fillFlightInfo
// DESCRIPTION :
// This function allocates memory for the destination
// and date.
// PARAMETERS :
// FlightInfo* flightInfo : it is a pointer to a struct where data will be stored.
// char* destination : it is a string representing destination.
// char* date : it is a string representing date.
// RETURNS :
// void
//

void fillFlightInfo(FlightInfo* flightInfo, char* destination, char* date) {

    flightInfo->destination = (char*)malloc((strlen(destination) + 1) * sizeof(char));
    flightInfo->date = (char*)malloc((strlen(date) + 1) * sizeof(char));

    strcpy(flightInfo->destination, destination);
    strcpy(flightInfo->date, date);
}

//
// FUNCTION : printFlightInfo
// DESCRIPTION :
// This function loop through array of struct and 
// print all the data
// PARAMETERS :
// FlightInfo* flightInfo : it is a pointer to an array of struct which contain all data
// RETURNS :
// void
//

void printFlightInfo(FlightInfo* flightInfo) {
    for (int i = 0; i < 10; i++) {
        printf("%-35s%-35s\n", flightInfo[i].destination, flightInfo[i].date);
    }
}
