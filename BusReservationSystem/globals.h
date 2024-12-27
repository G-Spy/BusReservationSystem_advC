#ifndef GLOBALS_H
#define GLOBALS_H

extern int globalCounter;
extern float globalRate;

extern char APP_NAME[];
extern int SLEEP_TIME ; 
extern char ERROR_INPUT_TYPE_MESSAGE[];
extern char INVALID_CHOICE_NUMBER_MESSAGE[];
extern char cities[50][50];
extern int numCities;
extern int numUsers;
extern int numBuses;
extern int loggedInUserId;
extern struct Bus buses[100];
extern struct User users[5];

#endif
