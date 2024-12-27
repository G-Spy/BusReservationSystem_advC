// BusReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// C Program to implement Bus Reservation System
#include "globals.h"
#include "Bus.h"
#include "User.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

// Function to display the welcome message to the application
void displayWelcomeApp() {
    printf("====================================\n");
    printf("*** Welcome to %s ***\n", APP_NAME);
    printf("====================================\n");
}

// Function to display the main menu
void displayMainMenu() {
    system("cls");
    displayWelcomeApp();
    printf("1. Login\n");
    printf("2. Exit\n");
    printf("\n> Enter your choice: ");
}

// Function to display the user menu
void displayUserMenu(struct User loggedInUser) {
    system("cls");
    printf("\n### Welcome %s ###\n\n", loggedInUser.username);
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Ticket\n");
    printf("3. Check Bus Status\n");
    printf("4. Logout\n");
    printf("\n> Enter your choice: ");
}


// ============= Main function ================================
int main() {

    struct User loggedInUser;

    while (1) {
        if (loggedInUserId == -1) {
            displayMainMenu();
            int choice;
            if (scanf_s("%d", &choice) == 1) {
                if (choice == 1) {
                    char login[50];
                    char password[50];

                    system("cls");
                    displayWelcomeApp();
                    printf("> Enter Username: ");
                    scanf("%s", login);
                    printf("> Enter Password: ");
                    scanf("%s", password);

                    loggedInUserId = loginUser(users, numUsers, login, password);
                    if (loggedInUserId == -1) {
                        printf("\n[ERROR]: Login failed. Please check your login and password.\n");
                        Sleep(SLEEP_TIME);
                    }
                    else {
                        system("cls");
                        loggedInUser = users[loggedInUserId];
                        printf("Login successful! Redirecting to Home ...\n");
                        Sleep(SLEEP_TIME);
                    }
                }
                else if (choice == 2) {
                    system("cls");
                    printf("Exiting the program...\n");
                    Sleep(SLEEP_TIME);
                    break;
                }
                else {
                    printf(INVALID_CHOICE_NUMBER_MESSAGE);
                    Sleep(SLEEP_TIME);
                }
            }
            else {
                printf(ERROR_INPUT_TYPE_MESSAGE);
                Sleep(SLEEP_TIME);
                // Clear invalid input from buffer
                while (getchar() != '\n');
            }

            
        }
        else {
            displayUserMenu(loggedInUser);
            int userChoice;
            if (scanf_s("%d", &userChoice) == 1) {
                switch (userChoice) {
                case 1:
                    bookTicket(buses, numBuses);
                    break;
                case 2:
                    cancelTicket(buses, numBuses);
                    break;
                case 3:
                    checkBusStatus(buses, numBuses);
                    break;
                case 4:
                    system("cls");
                    printf("Logging out...\n");
                    loggedInUserId = -1;
                    Sleep(SLEEP_TIME);
                    break;
                default:
                    printf(INVALID_CHOICE_NUMBER_MESSAGE);
                    Sleep(SLEEP_TIME);
                }
            }
            else {
                printf(ERROR_INPUT_TYPE_MESSAGE);
                Sleep(SLEEP_TIME);
                // Clear invalid input from buffer
                while (getchar() != '\n');
            }
  
        }
    }

    return 0;
}
