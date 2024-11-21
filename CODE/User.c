#include "User.h"
#include <stdio.h>
#include <string.h>

void loadUsers(const char *filename, User users[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening user data file.\n");
        return;
    }

    *count = 0;
    while (fscanf(file, "%[^,],%[^,],%lf\n", users[*count].username, users[*count].pin, &users[*count].balance) == 3) {
        (*count)++;
    }
    fclose(file);
}

int authenticate(User users[], int count, const char *username, const char *pin) {
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].pin, pin) == 0) {
            return i; // Return user index
        }
    }
    return -1; // Authentication failed
}
