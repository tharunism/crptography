#include <stdio.h>
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

