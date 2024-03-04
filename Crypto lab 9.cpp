#include <stdio.h>
#include <math.h>

// Function to calculate power
int power(int a, int b, int P) {
    if (b == 1)
        return a;

    else
        return (int)pow(a, b) % P;
}

// Function to perform key exchange
void keyExchange() {
    int P, G, a, b, A, B, keyA, keyB;

    // Publicly shared values
    P = 23; // Prime number
    G = 9;  // Primitive root of P

    // Private keys for Alice and Bob
    a = 4; // Alice's private key
    b = 3; // Bob's private key

    // Calculate public keys
    A = power(G, a, P);
    B = power(G, b, P);

    // Calculate secret key
    keyA = power(B, a, P);
    keyB = power(A, b, P);

    printf("Publicly Shared Values:\n");
    printf("P (Prime): %d, G (Primitive Root): %d\n\n", P, G);

    printf("Private Keys:\n");
    printf("Alice's Private Key (a): %d, Bob's Private Key (b): %d\n\n", a, b);

    printf("Public Keys:\n");
    printf("Alice's Public Key (A): %d, Bob's Public Key (B): %d\n\n", A, B);

    printf("Secret Key Calculated:\n");
    printf("Alice's Secret Key: %d, Bob's Secret Key: %d\n", keyA, keyB);
}

int main() {
    keyExchange();
    return 0;
}

