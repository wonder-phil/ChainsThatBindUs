#
# From: "The Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#
import datetime
import hashlib

class ExampleHash:
    
    def __init__(self):
        self.hashFunction = hashlib.new('sha256')

    def compHash(self, data):
        myBytes = data.encode()
        self.hashFunction.update(myBytes)
        print(self.hashFunction.hexdigest())


#
# The next example shows aspects of avalanche criteria
#

e = ExampleHash();

e.compHash("Hello");
e.compHash("Hello1");
e.compHash("Hello2");
e.compHash("Hello2453453453453345353453454564564");


    
