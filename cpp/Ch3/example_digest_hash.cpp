#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>

class ExampleHash {
public:
    ExampleHash() {}

    void compHash(const std::string& data) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);

        std::ostringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }

        std::cout << ss.str() << std::endl;
    }
};

int main() {
    ExampleHash e;

    e.compHash("Hello");
    e.compHash("Hello1");
    e.compHash("Hello2");
    e.compHash("Hello2453453453453345353453454564564");

    return 0;
}
