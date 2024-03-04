#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void calculateSHA512(const char *text) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512_CTX sha512;
    SHA512_Init(&sha512);
    SHA512_Update(&sha512, text, strlen(text));
    SHA512_Final(hash, &sha512);

    printf("SHA-512 Hash of '%s':\n", text);
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    const char *text = "Hello, World!";
    calculateSHA512(text);

    return 0;
}

