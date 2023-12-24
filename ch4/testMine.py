#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     

import sys
from Block import *

b=Block("empty","genesis block")

difficulty = int(sys.argv[1])
newBlock=b.mine(difficulty)
print("start<<" + newBlock.current_hash + ">>end")
