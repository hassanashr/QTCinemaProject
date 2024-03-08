#include "Users.h"

QString usernames[100] = {"admin", "test", "user1", "user2"};
QString passwords[100] = {"admin", "1234", "1101", "1102"};
int ages[100] = {20, 21, 22, 23};
int usersCount = 4; //Initial users are 4 in the system
int findUserIndex(QString username) {
    for(int i = 0; i < usersCount; i++)
        if(usernames[i] == username) return i;
    return -1;
}

void addNewUser(QString username) {
    usersCount++;
    usernames[usersCount-1]= username;
}

void addNewPass(QString password) {
    passwords[usersCount-1]= password;
}

void addAge(int age) {
    ages[usersCount-1]= age;
}
