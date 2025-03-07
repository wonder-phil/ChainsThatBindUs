#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     
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

# Python3> e = ExampleHash()
# Python3> e.compHash("Hello")
# > 185f8db32271fe25f561a6fc938b2e264306ec304eda518007d1764826381969
# Python3> e.compHash("Hello1")
# > 0d8741d6fca6218ca61c7180eeb4f97f57999e0611da71127222bc6942864dbae
# Python3> e.compHash("Hello2")
# > 7710852ea8b0ff3921f7086c9694483b214118e4308ff4b25ef114fdbf0fcd6f
# Python3> e.compHash("Hello2453453453453345353453454564564")
# > edf354bae21ef473702ba3af4c9090b4366907357bac21f6624ab880e01f6ce1

    
