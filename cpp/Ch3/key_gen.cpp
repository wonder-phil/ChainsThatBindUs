#include <iostream>
#include <fstream>
#include <openssl/rsa.h>
#include <openssl/pem.h>

void generate_rsa_keys() {
    int key_length = 1024;
    unsigned long e = RSA_F4;

    RSA *rsa = RSA_new();
    BIGNUM *bignum = BN_new();
    BN_set_word(bignum, e);

    RSA_generate_key_ex(rsa, key_length, bignum, nullptr);

    FILE *pub_file = fopen("public-key.pem", "w");
    if (pub_file == nullptr) {
        std::cerr << "Cannot open public-key.pem for writing." << std::endl;
        RSA_free(rsa);
        BN_free(bignum);
        return;
    }
    PEM_write_RSA_PUBKEY(pub_file, rsa);
    fclose(pub_file);

    FILE *sec_file = fopen("secret-key.pem", "w");
    if (sec_file == nullptr) {
        std::cerr << "Cannot open secret-key.pem for writing." << std::endl;
        RSA_free(rsa);
        BN_free(bignum);
        return;
    }
    PEM_write_RSAPrivateKey(sec_file, rsa, nullptr, nullptr, 0, nullptr, nullptr);
    fclose(sec_file);

    RSA_free(rsa);
    BN_free(bignum);
}

int main() {
    generate_rsa_keys();
    std::cout << "RSA keys generated and saved to files." << std::endl;
    return 0;
}
