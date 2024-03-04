#include <stdio.h>
#include <string.h>

void vigenereCipherEncrypt(char *message, char *key) {
    int keyLen = strlen(key), msgLen = strlen(message), i, j;
    char newKey[msgLen], encryptedMsg[msgLen];

    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    for (i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((message[i] + newKey[i]) % 26) + 'A';

    encryptedMsg[i] = '\0';

    printf("Encrypted Message: %s\n", encryptedMsg);
}

void vigenereCipherDecrypt(char *message, char *key) {
    int keyLen = strlen(key), msgLen = strlen(message), i, j;
    char newKey[msgLen], decryptedMsg[msgLen];

    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    for (i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((message[i] - newKey[i]) + 26) % 26) + 'A';

    decryptedMsg[i] = '\0';

    printf("Decrypted Message: %s\n", decryptedMsg);
}

int main() {
    char message[] = "HELLOWORLD";
    char key[] = "KEY";

    vigenereCipherEncrypt(message, key);
    vigenereCipherDecrypt(message, key);

    return 0;
}

