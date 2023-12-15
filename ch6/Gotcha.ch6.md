# BlockchainTechNotes - Gotchas Chapter 6

# From: "The Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#

## Some common gotchas

1. Check that RPis can see each other.
   Use ifconfig on each RPi to get its IPv4 address
   Rpi 1> ifconfig
   Find the IPv4 address IP_1 the WiFi system assigned to this RPi
   Rpi 2> ifconfig
   Find the IPv4 address IP_2 the WiFi system assigned to this RPi

   Rpi_1> ping IP_2   # check that RPi_1 can get to RPi_2
   After 30 seconds, type CTRL-C
   On the bottom check for the % packet-loss.  There should be 0% loss
   
   Rpi_2> ping IP_1   # check that RPi_2 can get to RPi_1
   After 30 seconds, type CTRL-C
   On the bottom check for the % packet-loss.  There should be 0% loss
3. 
4. 

