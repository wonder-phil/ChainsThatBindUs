#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     
#
#
import datetime
import hashlib
import sys
import paho.mqtt.client as mqtt

# globals
mine = ""
blockData = ""
nonce = 0

def on_message(client, userdata, message):
  global blockData
  global mine
  if message.topic == "mine":
    print(message.topic + " topic says : " + message.payload.decode('utf-8'))
    mine = message.payload.decode('utf-8')
  elif message.topic == "blockData":
    print(message.topic + " topic says : " + message.payload.decode('utf-8'))
    blockData = message.payload.decode('utf-8')
  else:
    print(message.topic + " <unknown topic> says : " + message.payload.decode('utf-8'))

def run_chain():

  global mine
  global nonce

  client = mqtt.Client()
  client.connect("localhost", 1883)
  client.on_message = on_message
  client.clean_run = True
  client.subscribe("mine",qos=1)
  client.subscribe("blockData",qos=1)

  b = BlockMqtt("genesis","data")

  client.loop_start()
  while True:
    while True: # event loop - mine
      if len(mine) != 0:
        print("start mining")
        break
    x = b.mine(client,5)
    client.publish("mine","CC2 won!")
    mine = ""
    print(x)
    nonce = nonce + 1
    b.compHash()


class BlockMqtt:
  hashFunction = ""
  bHash = ""

  def __init__(self,prevHash, data):
    blockData = ""
    self.prevHash = prevHash
    self.data = data
    self.time = datetime.datetime.now()
    self.bHash = self.compHash()
    self.interrupted = False

  def compHash(self):
    hashFunction = hashlib.new('sha256')
    myStr = str(self.prevHash)+str(self.data)+str(self.time)+str(nonce)
    myBytes = myStr.encode()
    hashFunction.update(myBytes)
    self.bHash = hashFunction.hexdigest()

    return self.bHash

  def mine(self,client,diff):
    global mine
    global nonce
    global blockData
    blockData = ""

    self.interrupted = False
    #client.loop_start()
    self.target = "0"*diff

    while self.bHash[0:diff] != self.target:
      if len(blockData) != 0:
        print("break")
        self.interrupted = True
        break

      nonce = nonce + 3
      self.compHash()

    return self

  def update(self,prevHash,data):
    self.prevHash = prevHash
    self.data = data

  def __str__(self):
    s = 'prevHash: '+ self.prevHash + '\n'
    s = s + 'data: ' + self.data + '\n'
    s = s + 'time: ' + str(self.time) + '\n'
    s = s + 'nonce: ' + str(nonce) + '\n'
    s = s + 'interrupted: ' + str(self.interrupted) + '\n'
    s = s + 'bHash: ' + self.bHash + '\n'

    return s

