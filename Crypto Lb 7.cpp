// C program for demonstration of encrypting and decrypting messages using Blowfish algorithm logic

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <blowfish.h>#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int gcd(long int a, long int b);
long int encryptDecrypt(long int message, long int key, long int n);

int main() {
    long int p = 61;
    long int q = 53;
    long int n = p * q;
    long int phi = (p - 1) * (q - 1);
    long int e = 17;
    long int d = 2753;
    long int message = 88;

    long int encrypted = encryptDecrypt(message, e, n);
    long int decrypted = encryptDecrypt(encrypted, d, n);

    printf("Original Message: %ld\n", message);
    printf("Encrypted Message: %ld\n", encrypted);
    printf("Decrypted Message: %ld\n", decrypted);

    return 0;
}

long int gcd(long int a, long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long int encryptDecrypt(long int message, long int key, long int n) {
    long int result = 1;
    for (int i = 0; i < key; i++) {
        result = (result * message) % n;
    }
    return result;
}


int main() {
    char key[] = "ThisIsASecretKey";
    char plainText[] = "Hello, World!";
    char cipherText[1000];
    char decryptedText[1000];

    // Encrypting the message
    BF_KEY bfKey;
    BF_set_key(&bfKey, strlen(key), (unsigned char *)key);
    BF_ecb_encrypt((unsigned char *)plainText, (unsigned char *)cipherText, &bfKey, BF_ENCRYPT);

    printf("Encrypted Text: %s\n", cipherText);

    // Decrypting the message
    BF_set_key(&bfKey, strlen(key), (unsigned char *)key);
    BF_ecb_encrypt((unsigned char *)cipherText, (unsigned char *)decryptedText, &bfKey, BF_DECRYPT);

    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}

