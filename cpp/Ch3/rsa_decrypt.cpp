#include <iostream>
#include <fstream>
#include <vector>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

RSA* loadPrivateKey(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "rb");
    if (file == nullptr) {
        std::cerr << "Cannot open file " << filename << std::endl;
        return nullptr;
    }

    RSA* rsa = PEM_read_RSAPrivateKey(file, nullptr, nullptr, nullptr);
    fclose(file);

    if (rsa == nullptr) {
        unsigned long err = ERR_get_error();
        char err_msg[1024] = {};
        ERR_error_string_n(err, err_msg, sizeof(err_msg));
        std::cerr << "Error loading private key: " << err_msg << std::endl;
    }

    return rsa;
}

std::vector<unsigned char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Cannot open file " << filename << std::endl;
        return {};
    }

    std::vector<unsigned char> data(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());

    return data;
}

std::string decrypt(RSA* rsa, const std::vector<unsigned char>& encryptedData) {
    if (rsa == nullptr) {
        std::cerr << "RSA key is null" << std::endl;
        return "";
    }

    int keySize = RSA_size(rsa);
    std::vector<unsigned char> decrypted(keySize, 0);

    int result = RSA_private_decrypt(
        encryptedData.size(),
        encryptedData.data(),
        decrypted.data(),
        rsa,
        RSA_PKCS1_PADDING);

    if (result == -1) {
        unsigned long err = ERR_get_error();
        char err_msg[1024] = {};
        ERR_error_string_n(err, err_msg, sizeof(err_msg));
        std::cerr << "Error decrypting message: " << err_msg << std::endl;
        return "";
    }

    return std::string(decrypted.begin(), decrypted.begin() + result);
}

int main() {
    const std::string privateKeyFile = "secret-key.pem";
    RSA* rsa = loadPrivateKey(privateKeyFile);
    if (rsa == nullptr) {
        return 1;
    }

    const std::string encryptedFile = "encrypted_data.bin";
    std::vector<unsigned char> encryptedData = readFile(encryptedFile);

    std::string decrypted = decrypt(rsa, encryptedData);
    std::cout << "Decrypted message: " << decrypted << std::endl;

    RSA_free(rsa);
    return 0;
}
