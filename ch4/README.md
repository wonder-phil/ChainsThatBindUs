# Chapter 4 of Blockchain Tech Notes, by P. G. Bradford

#
# Block.py is a basic block
##
## Create and mine blocks in Python3
##
##>>> b0 = Block("genesis block", "transaction set 1")
##>>> print(b0)
prevHash: genesis block
data: transaction set 1
nonce: 0
current_hash: 0c7493e79277eb199094c37e2d744d66ca7e48b46a3a2115f1ade009feb9b089
##>>> b1 = Block(b0.current_hash, "transaction set 2")
##>>> b1 = b1.mine(3)
##>>> print(b1)
prevHash: 0c7493e79277eb199094c37e2d744d66ca7e48b46a3a2115f1ade009feb9b089
data: transaction set 2
nonce: 8969
current_hash: 000d787ab83445d5723522892f58c1de247e84857a4a32300bc7b06ab987f60b
##
##
##
# BlockChain.py is a very basic clockchain
#
##
##>>> from BlockChain import BlockChain
##>>> bc = BlockChain()
##>>> bc.compBlockChain(5,3)
##>>>  bc.printBlockChainHashes()
ed432dc0208f31131a5b6069c5e4ff039a18f78908098b6f81a655e606e757d3
00089d26301bd26868f4e94607313d577ac57c48b8b39ac0b89d454b87258317
000c9a48548e99bf7fe2a3e67b727a517c743d2fe0dbf873f0456faa5ec8c2fc
0000de5d2895d9ed2250c43acf84afed9ec90e686cc1b95de7ef8849d9d6f6a4
000cea2cdd7230295b4c633229aad3af454c1f1b9877dec517574fa8fa42d7d5
#
