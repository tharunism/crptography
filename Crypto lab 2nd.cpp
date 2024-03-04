#include <stdio.h>
#include <string.h>

void prepareMessage(char *msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (msg[i] == 'j') {
            msg[i] = 'i';
        }
    }
}

void encrypt(char *msg, char key[5][5]) {
    // Encryption logic here
}

void decrypt(char *msg, char key[5][5]) {
    // Decryption logic here
}

int main() {
    char key[5][5] = {{'p', 'l', 'a', 'y', 'f'},
                      {'i', 'r', 'e', 'x', 'm'},
                      {'b', 'c', 'd', 'g', 'h'},
                      {'k', 'n', 'o', 'q', 's'},
                      {'t', 'u', 'v', 'w', 'z'}};

    char message[] = "hello";
    
    prepareMessage(message);
    
    printf("Original Message: %s\n", message);
    
    encrypt(message, key);
    
    printf("Encrypted Message: %s\n", message);
    
    decrypt(message, key);
    
    printf("Decrypted Message: %s\n", message);

    return 0;
}

