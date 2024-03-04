#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void calculateSHA1(const char *text, unsigned char *digest) {
    SHA1((const unsigned char *)text, strlen(text), digest);
}

int main() {
    char text[] = "Hello, World!";
    unsigned char digest[SHA_DIGEST_LENGTH];

    calculateSHA1(text, digest);

    printf("SHA-1 Digest: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}

