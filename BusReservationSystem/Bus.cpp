#include "Bus.h"
#include "globals.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Booking.h"


int contains(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1; // Found the number
        }
    }
    return 0; // Not found
}

// Function to filter the available buses from a departure city to a destination cit
int* filterBuses(char departureCity[], char destinationCity[]) {
    printf("\n## Available Buse(s) From [%s] To [%s] :\n", departureCity, destinationCity);
    int* options = NULL;
    int size = 0;
    for (int i = 0; i < numBuses; i++) {
        if (strcmp(buses[i].departureCity, departureCity) == 0 &&
            strcmp(buses[i].destinationCity, destinationCity) == 0) {
            size++;
            printf(" %d. Bus Number: %d, Departure: %s, Arrival: %s, Fare: %.2f (%d seats left!)\n",
                size,
                buses[i].busNumber, buses[i].departureTime,
                buses[i].arrivalTime, buses[i].fare,
                buses[i].availableSeats);
            options = (int*)realloc(options, size * sizeof(int));
            options[size - 1] = i;

        }
    }
    return options;
}

// A util function used to append a city to a list of cities 
void appendCity(char cities[50][50], int* count, const char* newCity) {
    if (*count < 50) { // Ensure we don't exceed array capacity
        strcpy(cities[*count], newCity); // Copy new city into next available position
        (*count)++; // Increment the count of cities
    }
    else {
        printf("Array is full; cannot add more cities.\n");
    }
}

// Function to book tickets
void bookTicket(struct Bus buses[], int numBuses) {
    int choice;

    bool isValidChoice = false;

    int departureCityIndex = 1;
    char departureCityName[100];
    while (!isValidChoice) {
        system("cls");
        choice = 1;
        // Enter the departure city
        printf("## Departure City:\n");
        for (int i = 0; i < numCities;i++) {
            printf(" %d. %s\n", choice, cities[i]);
            choice++;
        }

        printf("\n > Enter Your Choice: ");

        if (scanf_s("%d", &choice) == 1) {
            if (choice > numCities || choice < 1) {
                printf(INVALID_CHOICE_NUMBER_MESSAGE);
                Sleep(SLEEP_TIME);
            }
            else {
                departureCityIndex = choice - 1;
                strcpy(departureCityName, cities[departureCityIndex]);
                isValidChoice = true;

            }
        }
        else {
            printf(ERROR_INPUT_TYPE_MESSAGE);
            Sleep(SLEEP_TIME);
            while (getchar() != '\n');
        }
    }

    isValidChoice = false;
    char destinationCities[50][50];
    char destinationCityName[100];

    while (!isValidChoice) {
        system("cls");
        choice = 1;

        printf("\n## Departure City: %s\n", departureCityName);

        // Enter the destination city
        printf("\n## Destination City:\n");
        int count = 0;

        for (int i = 0; i < numCities;i++) {
            if (i != departureCityIndex) {
                printf(" %d. %s\n", choice, cities[i]);
                appendCity(destinationCities, &count, cities[i]);
                choice++;
            }
        }

        int destinationCityIndex = -1;

        printf("\n > Enter Your Choice: ");
        if (scanf_s("%d", &choice) == 1) {
            if (choice > numCities - 1 || choice < 1) {
                printf(INVALID_CHOICE_NUMBER_MESSAGE);
                Sleep(SLEEP_TIME);
            }
            else {
                strcpy(destinationCityName, destinationCities[choice - 1]);
                for (int i = 0; i < numCities; i++) {
                    if (strcmp(cities[i], destinationCityName) == 0) {
                        destinationCityIndex = i;
                        break;
                    }
                }
                isValidChoice = true;
            }
        }
        else {
            printf(ERROR_INPUT_TYPE_MESSAGE);
            Sleep(SLEEP_TIME);
            while (getchar() != '\n');
        }
    }


    isValidChoice = false;

    while (!isValidChoice) {
        system("cls");
        printf("\n## Departure City: %s\n", departureCityName);
        printf("\n## Destination City: %s\n", destinationCityName);
        // view available buses and ask user to select
        int* busOptions;
        busOptions = filterBuses(departureCityName, destinationCityName);

        printf("\n > Enter Your Choice: ");
        if (scanf_s("%d", &choice) == 1) {
            // Find the bus with the given busNumber
            int l = sizeof(*busOptions) / sizeof(busOptions[0]);
            if (choice > l || choice < 1) {
                printf(INVALID_CHOICE_NUMBER_MESSAGE);
                Sleep(SLEEP_TIME);
            }
            else {

                printf(" > Enter Number of Seats : ");
                int seatsToBook;
                scanf_s("%d", &seatsToBook);

                if (buses[busOptions[choice - 1]].availableSeats < seatsToBook) {
                    printf("\n[ERROR]: Sorry, only %d seats are available.\n", buses[busOptions[choice - 1]].availableSeats);
                    Sleep(SLEEP_TIME);
                }
                else {
                    // Add booking
                    if (bookingCount == 0) {
                        bookings[bookingCount].userId = loggedInUserId;
                        bookings[bookingCount].busNumber = buses[busOptions[choice - 1]].busNumber;
                        bookings[bookingCount].bookedSeats = seatsToBook;
                        bookingCount++;
                    }
                    else {
                        bool alreadyBookedBus = false;
                        for (int i = 0; i < bookingCount;i++) {
                            if (bookings[i].userId == loggedInUserId && bookings[i].busNumber == buses[busOptions[choice - 1]].busNumber) {
                                bookings[i].bookedSeats += seatsToBook;
                                alreadyBookedBus = true;
                                break;
                            }
                        }
                        if (!alreadyBookedBus) {
                            bookings[bookingCount].userId = loggedInUserId;
                            bookings[bookingCount].busNumber = buses[busOptions[choice - 1]].busNumber;
                            bookings[bookingCount].bookedSeats = seatsToBook;
                            bookingCount++;
                        }
                    }
                    

                    buses[busOptions[choice - 1]].availableSeats -= seatsToBook;
                    printf("\n *** Booking successful!");
                    printf("\n *** %d seats booked on Bus %d.\n", seatsToBook, buses[busOptions[choice - 1]].busNumber);
                    Sleep(SLEEP_TIME);
                    isValidChoice = true;
                }
            }
        }
        else {
            printf(ERROR_INPUT_TYPE_MESSAGE);
            Sleep(SLEEP_TIME);
            while (getchar() != '\n');
        }

        // free memory
        free(busOptions);


    }


}

// Function to cancel tickets
void cancelTicket(struct Bus buses[], int numBuses) {
    bool isValidChoice = false;
    int bookedBusesId[100];
    int counter = 0;
    while (!isValidChoice) {
        system("cls");
        // show booked buses
        printf("### Cancel Booking ###\n\n");
        if (bookingCount == 0) {
            printf("[WARNING] NO BOOKING AVAILABLE !\n");
            Sleep(SLEEP_TIME);
            // Clear invalid input from buffer
            while (getchar() != '\n');
            break;
            
        }
        for (int i = 0; i < bookingCount; i++) {
            if (bookings[i].userId == loggedInUserId) {
                if (bookings[i].bookedSeats != 0) {
                    printf(" - Bus Number: %d, Seats Booked: %d\n",
                        bookings[i].busNumber, bookings[i].bookedSeats);
                    bookedBusesId[counter] = bookings[i].busNumber;
                    counter++;
                }

            }
        }

        printf("\n > Enter Bus Number: ");
        int busNumber;
        if (scanf_s("%d", &busNumber) == 1) {
            if (!contains(bookedBusesId, counter, busNumber)) {
                printf("\n[ERROR]:No booking for this bus number!");
                Sleep(SLEEP_TIME);
                // Clear invalid input from buffer
                while (getchar() != '\n');
            }
            else {


                printf(" > Enter Number of Seats to Cancel: ");
                int seatsToCancel;
                scanf_s("%d", &seatsToCancel);


                // Find the bus with the given busNumber
                int busIndex = -1;
                for (int i = 0; i < numBuses; i++) {
                    if (buses[i].busNumber == busNumber) {
                        busIndex = i;
                        break;
                    }
                }

                for (int i = 0; i < bookingCount;i++) {
                    if (bookings[i].userId == loggedInUserId && bookings[i].busNumber == busNumber) {
                        
                        if (seatsToCancel > bookings[i].bookedSeats) {
                            printf("\n[ERROR]: You can't cancel more seats than were booked.\n");
                            Sleep(SLEEP_TIME);
                            while (getchar() != '\n');
                        }
                        else {
                            buses[busIndex].availableSeats += seatsToCancel;
                            bookings[i].bookedSeats -= seatsToCancel;
                            printf("\n ** Cancellation successful!.");
                            printf("\n ** %d seats canceled on Bus Number %d!.\n", seatsToCancel, busNumber);
                            isValidChoice = true;
                            Sleep(SLEEP_TIME);
                            while (getchar() != '\n');
   
                        }
                    }
                }

               
            }

        }
        else {
            printf(ERROR_INPUT_TYPE_MESSAGE);
            Sleep(SLEEP_TIME);
            while (getchar() != '\n');
        }
        

    
    }
}

// Function to check bus status
void checkBusStatus(struct Bus buses[], int numBuses) {
    bool isValidChoice = false;
    int busNumber;
    while (!isValidChoice) {
        system("cls");
        printf("\n> Enter Bus Number: ");
        if (scanf_s("%d", &busNumber) == 1) {

            // Find the bus with the given busNumber
            int busIndex = -1;
            for (int i = 0; i < numBuses; i++) {
                if (buses[i].busNumber == busNumber) {
                    busIndex = i;
                    break;
                }
            }

            if (busIndex != -1) {
                isValidChoice = true;
                printf("\n --------------------------------------------- \n");
                printf("\n* Bus Number: %d\n", buses[busIndex].busNumber);
                printf("* Source: %s\n", buses[busIndex].departureCity);
                printf("* Destination: %s\n", buses[busIndex].destinationCity);
                printf("* Total Seats: %d\n", buses[busIndex].totalSeats);
                printf("* Available Seats: %d\n", buses[busIndex].availableSeats);
                printf("* Fare: %.2f\n", buses[busIndex].fare);
                printf("\n --------------------------------------------- \n");

                printf("\nPress any key to continue...\n");
                _getch();
            }
            else {
                printf("Bus with Bus Number %d not found.\n", busNumber);
                Sleep(SLEEP_TIME);
            }
        }
        else {
            printf(ERROR_INPUT_TYPE_MESSAGE);
            Sleep(SLEEP_TIME);

        }
    }
}
