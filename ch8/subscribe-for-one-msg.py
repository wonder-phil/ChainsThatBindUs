#
#
# From: "The Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#
#
import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect("localhost", 1883)  # broker on localhost!

# global
mydata = ""

def on_message(client, userdata, message):
  global mydata
  print(message.topic + " " + message.payload.decode('utf-8'))
  mydata = message.payload.decode('utf-8')

client.on_message = on_message
client.subscribe("break-event-loop",qos=1)
client.loop_start()
while True:
    if len(mydata) != 0:
       break
      
client.loop_stop()

