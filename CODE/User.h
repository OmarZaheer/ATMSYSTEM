#ifndef USER_H
#define USER_H

typedef struct {
    char username[50];
    char pin[5];
    double balance;
} User;

void loadUsers(const char *filename, User users[], int *count);
int authenticate(User users[], int count, const char *username, const char *pin);

#endif
