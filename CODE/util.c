#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *output, int key[2][2]) {
    int len = strlen(input);
    for (int i = 0; i < len; i += 2) {
        output[i] = (key[0][0] * input[i] + key[0][1] * input[i + 1]) % 26 + 'A';
        output[i + 1] = (key[1][0] * input[i] + key[1][1] * input[i + 1]) % 26 + 'A';
    }
    output[len] = '\0';
}

void decrypt(char *input, char *output, int key[2][2]) {
    // Key matrix inverse modulo 26
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26; // Ensure positive determinant

    // Find modular multiplicative inverse of det mod 26
    int detInv = -1;
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1) {
            detInv = i;
            break;
        }
    }
    if (detInv == -1) {
        printf("Error: Key matrix is not invertible modulo 26.\n");
        return;
    }

    // Calculate inverse key matrix
    int invKey[2][2];
    invKey[0][0] = (key[1][1] * detInv) % 26;
    invKey[0][1] = (-key[0][1] * detInv) % 26;
    invKey[1][0] = (-key[1][0] * detInv) % 26;
    invKey[1][1] = (key[0][0] * detInv) % 26;

    // Ensure positive values in the inverse matrix
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (invKey[i][j] < 0) invKey[i][j] += 26;
        }
    }

    // Decrypt the input using the inverse key matrix
    int len = strlen(input);
    for (int i = 0; i < len; i += 2) {
        output[i] = (invKey[0][0] * (input[i] - 'A') + invKey[0][1] * (input[i + 1] - 'A')) % 26 + 'A';
        output[i + 1] = (invKey[1][0] * (input[i] - 'A') + invKey[1][1] * (input[i + 1] - 'A')) % 26 + 'A';
    }
    output[len] = '\0';
}
