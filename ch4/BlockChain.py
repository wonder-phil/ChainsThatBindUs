#
# From: Blockchain Tech Notes by P. G. Bradford
#

from Block import *
import copy

class BlockChain:
    blockChain = []
    genesisBlock = Block("genesis block", "transaction set 1")
    dataList = ["a","b","c","d","e","f","g"]

    def compBlockChain(self, totalBlocks, difficulty):
        newBlock = self.genesisBlock
        self.blockChain.append(self.genesisBlock)
        for i in range(0,totalBlocks -1):
            newBlock = Block(newBlock.current_hash,self.dataList[i])
            newBlock = newBlock.mine(difficulty);
            self.blockChain.append(newBlock)

    def printBlockChainHashes(self):
        for b in self.blockChain:
            print(b.current_hash)

    def validateBlockChain(self):
        valid = True
        b = self.blockChain[0]
        if b != self.genesisBlock:
            valid = False
        temp = copy.deepcopy(b)
        lastHash = temp.compHash()
        if valid:
            for b in self.blockChain[1:]:
                if b.prevHash != lastHash:
                    valid = False
                else:
                    temp = copy.deepcopy(b)
                    lastHash = temp.compHash()
                
        return valid

    def removeBlockChain(self):
        blockChain.clear()
        
    
