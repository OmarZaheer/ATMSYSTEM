#include "util.h"
#include "User.h"
#include "Transaction.h"
#include <stdio.h>

#define MAX_USERS 100

int main() {
    User users[MAX_USERS];
    int userCount;
    loadUsers("users.csv", users, &userCount);

    char username[50], pin[5];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter PIN: ");
    scanf("%s", pin);

    int userIndex = authenticate(users, userCount, username, pin);
    if (userIndex == -1) {
        printf("Authentication failed.\n");
        return 1;
    }

    printf("Welcome, %s!\n", users[userIndex].username);
    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        double amount;

        switch (choice) {
            case 1:
                balanceInquiry(&users[userIndex]);
                break;
            case 2:
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                deposit(&users[userIndex], amount);
                saveTransaction("transactions.csv", username, "Deposit", amount);
                break;
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                withdraw(&users[userIndex], amount);
                saveTransaction("transactions.csv", username, "Withdraw", amount);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
