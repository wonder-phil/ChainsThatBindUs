#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     
#
import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect("localhost", 1883)
client.publish("blockData", "Hello, world!")

client.disconnect()




