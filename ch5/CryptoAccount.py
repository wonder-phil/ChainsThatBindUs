#
# From: Blockchain Tech Notes by P. G. Bradford
#

class CryptoAccount(object):

    class Instance:
        publicKey = None
        secretKey= None
        dateTime  = None
        expiration = None
        block  = None
        amount = None
    
    def __init__(self,publicKey, secretKey, dateTime, expiration, block, amount):
        self.instance = self.Instance()
        self.instance.publicKey = publicKey
        self.instance.secretKey = secretKey
        self.instance.dateTime = dateTime
        self.instance.expiration = expiration
        self.instance.block = block
        self.instance.amount = amount
