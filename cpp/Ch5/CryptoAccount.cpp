#include <string>
#include <ctime>

class CryptoAccount {
public:
    struct Instance {
        std::string publicKey;
        std::string secretKey;
        std::time_t dateTime;
        std::time_t expiration;
        int block;
        double amount;
    };

    CryptoAccount(std::string publicKey, std::string secretKey, std::time_t dateTime, std::time_t expiration, int block, double amount) {
        instance.publicKey = publicKey;
        instance.secretKey = secretKey;
        instance.dateTime = dateTime;
        instance.expiration = expiration;
        instance.block = block;
        instance.amount = amount;
    }

private:
    Instance instance;
};

