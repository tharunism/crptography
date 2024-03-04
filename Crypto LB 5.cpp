#include <stdio.h>
#include <string.h>

void encryptRailFence(char* message, int rails);
void decryptRailFence(char* message, int rails);

int main() {
    char message[] = "HELLOWORLD";
    int rails = 3;

    printf("Original Message: %s\n", message);

    encryptRailFence(message, rails);
    printf("Encrypted Message: %s\n", message);

    decryptRailFence(message, rails);
    printf("Decrypted Message: %s\n", message);

    return 0;
}

void encryptRailFence(char* message, int rails) {
    int len = strlen(message);
    char railFence[rails][len];
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            railFence[i][j] = '\n';
        }
    }

    int row = 0;
    int dir = 0;

    for (int i = 0; i < len; i++) {
        railFence[row][i] = message[i];

        if (row == 0 || row == rails - 1) {
            dir = 1 - dir;
        }

        row += dir;
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railFence[i][j] != '\n') {
                message[index++] = railFence[i][j];
            }
        }
    }
    message[index] = '\0';
}

void decryptRailFence(char* message, int rails) {
    int len = strlen(message);
    char railFence[rails][len];
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            railFence[i][j] = '\n';
        }
    }

    int row = 0;
    int dir = 0;

    for (int i = 0; i < len; i++) {
        railFence[row][i] = '*';

        if (row == 0 || row == rails - 1) {
            dir = 1 - dir;
        }

        row += dir;
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (railFence[i][j] == '*') {
                railFence[i][j] = message[index++];
            }
        }
    }

    row = 0;
    dir = 0;

    for (int i = 0; i < len; i++) {
        message[i] = railFence[row][i];

        if (row == 0 || row == rails - 1) {
            dir = 1 - dir;
        }

        row += dir;
    }
}

