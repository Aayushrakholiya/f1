#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#pragma warning (disable: 4996)

typedef struct {
    char* destination;
    char* date;
} FlightInfo;

void fillFlightInfo(FlightInfo* flightInfo, char* destination, char* date) {

    

    
    flightInfo->destination = (char *) malloc((strlen(destination) + 1) * sizeof(char));// malloc (30 * sizeof(char)+1)
    flightInfo->date = (char *) malloc((strlen(date) + 1) * sizeof(char));


    strcpy(flightInfo->destination, destination);
    strcpy(flightInfo->date, date);
}

void printFlightInfo(FlightInfo* flightInfo) {
    for (int i = 0; i < 10; i++) {
        printf("%-35s%-35s\n", flightInfo[i].destination, flightInfo[i].date);
    }
}

int main() {
    FlightInfo flightInfo[10];

    for (int i = 0; i < 10; i++) {
        char destination[30] = {0};
        char date[30] = {0};

        printf("Enter name of destination %d: ", i + 1);
        
        destination[strcspn(destination, "\n")] = '\0';
        fgets(destination, sizeof(destination), stdin);

        printf("Enter date of flight %d: ", i + 1);
        
        date[strcspn(date, "\n")] = '\0';
        fgets(date, sizeof(date), stdin);

        fillFlightInfo(&flightInfo[i], destination, date);
    }


    printFlightInfo(flightInfo);


    free(flightInfo->destination);
    free(flightInfo->date);

    return 0;
}
