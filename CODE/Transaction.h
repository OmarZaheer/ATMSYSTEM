#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "User.h"
void displayMenu();
void balanceInquiry(User *user);
void deposit(User *user, double amount);
void withdraw(User *user, double amount);
void saveTransaction(const char *filename, const char *username, const char *operation, double amount);

#endif
