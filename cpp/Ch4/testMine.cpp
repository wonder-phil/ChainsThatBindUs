#include <iostream>
#include <string>
#include "Block.h" 

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [difficulty level]" << std::endl;
        return 1;
    }

    int difficulty = std::stoi(argv[1]);
    Block b("empty", "genesis block");

    Block newBlock = b.mine(difficulty);
    std::cout << "start<<" << newBlock.getCurrentHash() << ">>end" << std::endl;

    return 0;
}