#ifndef USER_H
#define USER_H

struct User {
    char login[50];
    char password[50];
    char username[50];
};

int loginUser(struct User users[], int numUsers, char username[], char password[]);

#endif
