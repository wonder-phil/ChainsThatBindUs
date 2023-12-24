## From: "Chains that bind us" by Phillip G. Bradford#  https://github.com/wonder-phil/ChainsThatBindUs#     import paho.mqtt.client as mqtt
client = mqtt.Client()
client.connect("localhost", 1883)
def on_message(client, userdata, message):
  print(message.topic + " " + message.payload.decode('utf-8'))

client.on_message = on_message
client.subscribe("test",qos=1)
client.loop_forever()
