#ifndef BUS_H
#define BUS_H

// Define a structure to store bus information
struct Bus {
    int busNumber;
    char departureCity[50];
    char destinationCity[50];
    int totalSeats;
    int availableSeats;
    float fare;
    char departureTime[20];
    char arrivalTime[20];
};

void bookTicket(struct Bus buses[], int numBuses);
void cancelTicket(struct Bus buses[], int numBuses);
void checkBusStatus(struct Bus buses[], int numBuses);
int* filterBuses(char departureCity[], char destinationCity[]);
void appendCity(char cities[50][50], int* count, const char* newCity);
void busStatusByBusNumber();

#endif
