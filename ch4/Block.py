#
# From: Blockchain Tech Notes by P. G. Bradford
#

#import datetime
import hashlib


#
#  from Block import Block
#

class Block:
    hashFunction = hashlib.new('sha256')
    current_hash = ""
    
    def __init__(self, prevHash, data):
        self.prevHash = prevHash
        self.data = data
        self.nonce = 0
        self.current_hash = self.compHash()

    def compHash(self):
        myStr = str(self.prevHash)+str(self.data)+str(self.nonce)
        myBytes = myStr.encode()
        self.hashFunction.update(myBytes)
        self.current_hash = self.hashFunction.hexdigest()
        return self.current_hash

    def mine(self,diff):
        self.target = "0"*diff
        while self.current_hash[0:diff] != self.target:
            self.nonce = self.nonce + 1
            self.compHash()
        #print("Block mined: ", self.current_hash)
        return self

    def update(self,prevHash,data):
        self.prevHash = prevHash
        self.data = data

    def __str__(self):
        s = 'prevHash: '+ self.prevHash + '\n'
        s = s + 'data: ' + self.data + '\n'
        s = s + 'nonce: ' + str(self.nonce) + '\n'
        s = s + 'current_hash: ' + self.current_hash + '\n'
        return s
