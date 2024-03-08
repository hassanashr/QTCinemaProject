#ifndef USERS_H
#define USERS_H

#include <QString>

// These are 3 global arrays of maximam size 100 for: usernames, passwords, and ages
extern QString usernames[100];
extern QString passwords[100];
extern int ages[100];
// the usersCount int is for current number of users: initally 0
extern int usersCount;
extern int findUserIndex(QString username);
extern void addNewUser(QString username); //method to add a new user
extern void addNewPass(QString password); //method to add a new password
extern void addAge(int age); //method to add a new age


#endif // USERS_H
