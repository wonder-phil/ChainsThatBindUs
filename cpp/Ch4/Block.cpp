#include <iostream>
#include <sstream>
#include <string>
#include <openssl/sha.h>

class Block {
private:
    std::string prevHash;
    std::string data;
    unsigned long nonce;
    std::string current_hash;

    std::string sha256(const std::string& str) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str.c_str(), str.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::uppercase << ((int)hash[i] & 0xff);
        }
        return ss.str();
    }

public:
    Block(const std::string& prevHash, const std::string& data) 
        : prevHash(prevHash), data(data), nonce(0) {
        current_hash = compHash();
    }

    std::string compHash() {
        std::string myStr = prevHash + data + std::to_string(nonce);
        current_hash = sha256(myStr);
        return current_hash;
    }

    Block& mine(int diff) {
        std::string target = std::string(diff, '0');
        while (current_hash.substr(0, diff) != target) {
            nonce++;
            compHash();
        }
        //std::cout << "Block mined: " << current_hash << std::endl;
        return *this;
    }

    void update(const std::string& prevHash, const std::string& data) {
        this->prevHash = prevHash;
        this->data = data;
    }

    std::string toString() const {
        std::stringstream s;
        s << "prevHash: " << prevHash << '\n'
          << "data: " << data << '\n'
          << "nonce: " << nonce << '\n'
          << "current_hash: " << current_hash << '\n';
        return s.str();
    }
};

int main() {
    Block block("0000", "Test Data");
    block.mine(4);
    std::cout << block.toString() << std::endl;
    return 0;
}
