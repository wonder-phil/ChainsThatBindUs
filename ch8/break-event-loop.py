#
#
# From: "The Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#

# break-event-loop.py
#
import paho.mqtt.client as mqtt

client = mqtt.Client()
client.connect("localhost", 1883) # broker on localhost!
client.publish("break-event-loop", "Busting your loop!")

client.disconnect()
