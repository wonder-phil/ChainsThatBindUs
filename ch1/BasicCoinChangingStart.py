#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     
import numpy as np

class GreedyChange:

    def __init__(self, denominations, givenTotal):
        self.denominations = np.flip(np.sort(denominations)) # smallest to largest
        self.coinAmounts = [0 for i in range(len(self.denominations))]
        self.givenTotal = givenTotal

    def computeChange(self):
        total = self.givenTotal
        indexLargestRemaining = 0
        while total > 0:
            self.coinAmounts[indexLargestRemaining] = total // self.denominations[indexLargestRemaining]
            total = self.givenTotal % self.denominations[indexLargestRemaining]
            indexLargestRemaining = indexLargestRemaining + 1


    def __str__(self):
        s = 'Given total: '+ str(self.givenTotal) + '\n'
        s = s + 'Denominations: ' + str(self.denominations) + '\n'
        s = s + 'Numbers of coins using greedy' + '\n'
        s = s + '-----------------------------\n'
        for (amount, coin) in zip(self.coinAmounts, self.denominations):
            s = s + str(amount) + ' of ' + str(coin) + '\n'
            
        return s


    
