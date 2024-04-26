#include <iostream>
#include <fstream>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

RSA* loadPublicKey(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "rb");
    if (!file) {
        std::cerr << "Unable to open public key file: " << filename << std::endl;
        return nullptr;
    }

    RSA* rsa = PEM_read_RSA_PUBKEY(file, nullptr, nullptr, nullptr);
    fclose(file);

    if (!rsa) {
        std::cerr << "Failed to load public key from: " << filename << std::endl;
    }

    return rsa;
}

std::vector<unsigned char> encrypt(RSA* rsa, const std::string& data) {
    if (!rsa) {
        std::cerr << "RSA context is null" << std::endl;
        return {};
    }

    int rsaSize = RSA_size(rsa);
    std::vector<unsigned char> encrypted(rsaSize);

    int result = RSA_public_encrypt(data.size(), 
                                    reinterpret_cast<const unsigned char*>(data.c_str()),
                                    encrypted.data(), rsa, RSA_PKCS1_PADDING);

    if (result == -1) {
        unsigned long err = ERR_get_error();
        char err_msg[1024] = {};
        ERR_error_string_n(err, err_msg, sizeof(err_msg));
        std::cerr << "Error encrypting message: " << err_msg << std::endl;
        return {};
    }

    encrypted.resize(result);
    return encrypted;
}

int main() {
    const std::string publicKeyFile = "public-key.pem";
    RSA* rsa = loadPublicKey(publicKeyFile);
    if (!rsa) {
        return 1;
    }

    const std::string data = "Greetings - Today is a great day!";
    std::vector<unsigned char> encrypted = encrypt(rsa, data);

    std::ofstream fileOut("encrypted_data.bin", std::ios::binary);
    if (!fileOut) {
        std::cerr << "Unable to open file for writing encrypted data." << std::endl;
        RSA_free(rsa);
        return 1;
    }

    fileOut.write(reinterpret_cast<const char*>(encrypted.data()), encrypted.size());
    fileOut.close();

    RSA_free(rsa);
    return 0;
}
