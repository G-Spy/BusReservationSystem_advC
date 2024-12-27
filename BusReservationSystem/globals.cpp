#include "globals.h"
#include "Bus.h"
#include "User.h"


// Globals variables 
char APP_NAME[] = "EPITA Express";
int SLEEP_TIME = 3000; // 3 seconds
char ERROR_INPUT_TYPE_MESSAGE[] = "\n[ERROR]: Invalid input. Please enter a number of the choice.\n";
char INVALID_CHOICE_NUMBER_MESSAGE[] = "\n[ERROR]: Invalid Choice. Please enter the available option number.\n";
char cities[50][50] = { "Paris", "Bordeaux","Lyon", "Toulouse", "Marseille" };
int numCities = 5;
int numUsers = 5;
int numBuses = 40;
int loggedInUserId = -1;

// Initialize bus data: {busNumber, departureCity, destinationCity, totalSeats, availableSeats, fare, departureTime, arrivalTime}
struct Bus buses[100] = {
    // from Paris 
    //// AM
    {101, "Paris", "Lyon", 50, 50, 500.0, "9h00","11h30"},
    {102, "Paris", "Bordeaux", 40, 40, 400.0, "9h00","11h30"},
    {103, "Paris", "Toulouse", 30, 30, 300.0, "9h00","11h30"},
    {104, "Paris", "Marseille", 30, 30, 300.0, "9h00","11h30"},
    //// PM
    {105, "Paris", "Lyon", 50, 50, 500.0, "14h00","16h30"},
    {106, "Paris", "Bordeaux", 40, 40, 400.0, "14h00","16h30"},
    {107, "Paris", "Toulouse", 30, 30, 300.0, "14h00","16h30"},
    {108, "Paris", "Marseille", 30, 30, 300.0, "14h00","16h30"},

    // from Bordeaux
    //// AM
    {109, "Bordeaux", "Paris", 30, 30, 300.0, "9h00","11h30"},
    {110, "Bordeaux", "Lyon", 30, 30, 300.0, "9h00","11h30"},
    {111, "Bordeaux", "Marseille", 30, 30, 300.0, "9h00","11h30"},
    {112, "Bordeaux", "Toulouse", 30, 30, 300.0, "9h00","11h30"},
    //// PM
    {113, "Bordeaux", "Paris", 30, 30, 300.0, "14h00","16h30"},
    {114, "Bordeaux", "Lyon", 30, 30, 300.0, "14h00","16h30"},
    {115, "Bordeaux", "Marseille", 30, 30, 300.0, "14h00","16h30"},
    {116, "Bordeaux", "Toulouse", 30, 30, 300.0, "14h00","16h30"},

    // from Lyon
    //// AM
    {117, "Lyon", "Paris", 30, 30, 300.0, "9h00","11h30"},
    {118, "Lyon", "Bordeaux", 30, 30, 300.0, "9h00","11h30"},
    {119, "Lyon", "Toulouse", 30, 30, 300.0, "9h00","11h30"},
    {120, "Lyon", "Marseille", 30, 30, 300.0, "9h00","11h30"},
    //// PM
    {121, "Lyon", "Paris", 30, 30, 300.0, "14h00","16h30"},
    {122, "Lyon", "Bordeaux", 30, 30, 300.0, "14h00","16h30"},
    {123, "Lyon", "Toulouse", 30, 30, 300.0, "14h00","16h30"},
    {124, "Lyon", "Marseille", 30, 30, 300.0, "14h00","16h30"},

    // From Toulouse
    //// AM
    {125, "Toulouse", "Paris", 30, 30, 300.0, "9h00","11h30"},
    {126, "Toulouse", "Bordeaux", 30, 30, 300.0, "9h00","11h30"},
    {127, "Toulouse", "Lyon", 30, 30, 300.0, "9h00","11h30"},
    {128, "Toulouse", "Marseille", 30, 30, 300.0, "9h00","11h30"},
    //// PM
    {129, "Toulouse", "Paris", 30, 30, 300.0, "14h00","16h30"},
    {130, "Toulouse", "Bordeaux", 30, 30, 300.0, "14h00","16h30"},
    {131, "Toulouse", "Lyon", 30, 30, 300.0, "14h00","16h30"},
    {132, "Toulouse", "Marseille", 30, 30, 300.0, "14h00","16h30"},

    // From Marseille
    //// AM
    {133, "Marseille", "Paris", 30, 30, 300.0, "9h00","11h30"},
    {134, "Marseille", "Bordeaux", 30, 30, 300.0, "9h00","11h30"},
    {135, "Marseille", "Lyon", 30, 30, 300.0, "9h00","11h30"},
    {136, "Marseille", "Toulouse", 30, 30, 300.0, "9h00","11h30"},
    //// PM
    {137, "Marseille", "Paris", 30, 30, 300.0, "14h00","16h30"},
    {138, "Marseille", "Bordeaux", 30, 30, 300.0, "14h00","16h30"},
    {139, "Marseille", "Lyon", 30, 30, 300.0, "14h00","16h30"},
    {140, "Marseille", "Toulouse", 30, 30, 300.0, "14h00","16h30"},

};


// Initialize user data: {login, password, username}
struct User users[5] = {
    {"user1", "pass1","Pascal Rothnemer"},
    {"user2", "pass2", "Raissa"},
    {"user3", "pass3", "Phillipa"},
    {"user4", "pass4","Diane"},
    {"user5", "pass5", "Emeric"},
};



