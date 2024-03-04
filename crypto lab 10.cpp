#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

void calculate_md5_hash(const char *message, unsigned char *digest) {
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, message, strlen(message));
    MD5_Final(digest, &context);
}

int main() {
    char message[] = "Hello, World!";
    unsigned char digest[MD5_DIGEST_LENGTH];

    calculate_md5_hash(message, digest);

    printf("Message: %s\n", message);
    printf("MD5 Digest: ");
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}
n
