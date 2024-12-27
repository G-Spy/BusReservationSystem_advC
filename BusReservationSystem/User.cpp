#include "User.h"
#include <string.h>

// Function to perform user login
int loginUser(struct User users[], int numUsers, char login[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].login, login) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return the index of the logged-in user
        }
    }
    return -1; // Return -1 if login fails
}


