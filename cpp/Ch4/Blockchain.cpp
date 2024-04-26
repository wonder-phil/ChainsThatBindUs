#include <iostream>
#include <vector>
#include <string>
#include "Block.h" // Assume this is the header file for the Block class

class BlockChain {
private:
    std::vector<Block> blockChain;
    Block genesisBlock;
    std::vector<std::string> dataList;

public:
    BlockChain() 
        : genesisBlock("genesis block", "transaction set 1"), 
          dataList({"a", "b", "c", "d", "e", "f", "g"}) {
        blockChain.push_back(genesisBlock);
    }

    void compBlockChain(int totalBlocks, int difficulty) {
        Block newBlock = genesisBlock;

        for (int i = 0; i < totalBlocks - 1; ++i) {
            newBlock = Block(newBlock.getCurrentHash(), dataList[i % dataList.size()]);
            newBlock.mine(difficulty);
            blockChain.push_back(newBlock);
        }
    }

    void printBlockChainHashes() {
        for (const auto& block : blockChain) {
            std::cout << block.getCurrentHash() << std::endl;
        }
    }

    bool validateBlockChain() {
        bool valid = true;
        Block temp = blockChain[0];
        std::string lastHash = temp.compHash();

        for (size_t i = 1; i < blockChain.size(); ++i) {
            const auto& b = blockChain[i];
            if (b.getPrevHash() != lastHash) {
                valid = false;
                break;
            }
            temp = b;
            lastHash = temp.compHash();
        }
        
        return valid;
    }

    void removeBlockChain() {
        blockChain.clear();
    }
};

int main() {
    BlockChain bc;
    bc.compBlockChain(5, 4);
    bc.printBlockChainHashes();

    if (bc.validateBlockChain()) {
        std::cout << "BlockChain is valid." << std::endl;
    } else {
        std::cout << "BlockChain is not valid." << std::endl;
    }

    return 0;
}
