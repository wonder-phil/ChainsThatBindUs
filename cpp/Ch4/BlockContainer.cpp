#include <iostream>
#include <string>
#include <ctime>
#include "Block.h" 

class BlockContainer {
private:
    Block block;
    std::time_t datetime;
    int difficulty;

public:
    BlockContainer(const Block& block, std::time_t datetime, int difficulty)
        : block(block), datetime(datetime), difficulty(difficulty) {}

    friend std::ostream& operator<<(std::ostream& os, const BlockContainer& bc) {
        os << "Block: " << bc.block.toString() << '\n'
           << "datetime: " << std::asctime(std::localtime(&bc.datetime))
           << "difficulty: " << bc.difficulty << '\n';
        return os;
    }
};

int main() {
    Block myBlock("previousHash", "data");
    std::time_t now = std::time(nullptr);
    int difficulty = 3;

    BlockContainer container(myBlock, now, difficulty);
    std::cout << container << std::endl;

    return 0;
}
