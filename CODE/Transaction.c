#include "Transaction.h"
#include <stdio.h>
#include "User.h"
void displayMenu() {
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
}

void balanceInquiry(User *user) {
    printf("Your balance is: %.2lf\n", user->balance);
}

void deposit(User *user, double amount) {
    user->balance += amount;
    printf("Deposited: %.2lf\n", amount);
}

void withdraw(User *user, double amount) {
    if (amount > user->balance) {
        printf("Insufficient funds.\n");
    } else {
        user->balance -= amount;
        printf("Withdrew: %.2lf\n", amount);
    }
}

void saveTransaction(const char *filename, const char *username, const char *operation, double amount) {
    FILE *file = fopen(filename, "a");
    if (file) {
        fprintf(file, "%s,%s,%.2lf\n", username, operation, amount);
        fclose(file);
    }
}
