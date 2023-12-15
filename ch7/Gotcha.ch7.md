# BlockchainTechNotes - Gotchas Chapter 7

# From: "The Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#

## Some common gotchas

0. Ensure you have network access to the RPis
   Ubuntu> ping <Rpi IP address>

1. If remote mining on an RPi does not work using the RPI_1_Mine() function.
   Check that your paramiko Python code can reach your RPi. 
   This can be done using a simple function with paramiko that creates a "hello-world.txt" file on the RPi.
   This file should be created in /home/rpi and it can be verified by SSH-ing into this RPi.
   
   If paramiko reaches your RPi, then ensure Block.py and testMine.py are both in 
   the directory /home/rpi
   
    
2. LOC-of-DRIVER path issue: The Ubuntu graphics driver location may vary based on the virtualizer

 <graphics type='spice' autoport='yes'>
      <gl enable='no' rendernode='/dev/dri/by-path/pci-0000:00:02.0-render'/>
    </graphics>
	
	The correct location can be found by connecting to the directory '/dev/dri/by-path/'
	and tabbing-out with the escape-key or tab-key on some machines with `pic-00...'
	This should give you the *entire* path NEW-PATH to put in the XML line:
	
	<gl enable='no' rendernode='NEW-PATH'/>
	
3. Kernel panic-not syncing: VFS: block (0,0) - this means qemu cannot read the RPi's disk (IMG or qcow2 formats).


