import datetime
import Block

class BlockContainer:
    Block block
    def __init__(self,block, datetime, difficulty):
        self.block = block
        self.datetime = datetime
        self.difficulty = difficulty
 
    def __str__(self):
        s = 'Block: '+ self.block + '\n'
        s = s + 'datetime: ' + str(self.datetime) + '\n'
        s = s + 'difficulty: ' + str(self.difficulty) + '\n'
 
        return s
