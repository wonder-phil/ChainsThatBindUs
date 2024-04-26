
The provided Python file implements a greedy algorithm for making change using a given set of coin denominations. It defines a class called GreedyChange, which takes a list of denominations and a total amount as input and computes the minimum number of coins needed to make the change. The algorithm iteratively selects the largest denomination that can be used without exceeding the remaining total until the total becomes zero.


#Steps to Run Rpi on Qemu: 

1. Have a working Ubuntu machine
2. On pi's "https://www.raspberrypi.org/software/operating-systems" website, download the latest 64-bit Lite OS image
3. Follow Instructions in book to the end of 7.3.2
4. Refer to images 7.1-7.4 for the initial commands to start Qemu and set-up Rpi
5. Continue following instructions from 7.3.3

#Descriptions:
1. Linux-devies.md --> contains information about ISO disk images 
2. QEMU-command-Ubuntu-32-bit.txt --> 
    - For 32-bit architecture 
    - ARM1176 CPU.
    - Memory --> 256 MB.
    - qcow2 disk image format.

3. QEMU-command-Ubuntu-First-RUN-IMG.txt -->
    - 64-bit Architecture
    - cortex-a72 CPU.
    - Disk image --> virtio-blk-pci device
    - contains initalization parameters 

4. QEMU-command-Ubuntu-First-RUN.txt -->
    - 64-bit Architecture
    - cortex-a72 CPU.
    - Disk image --> virtio-blk-pci device LITE version
    - contains initalization parameters 

5. QEMU-command-Ubuntu.txt -->
    - 64-bit Architecture
    - cortex-a72 CPU.
    - Disk image --> virtio-blk-pci device LITE version
    - Memory --> 256 MB.

6. SelectExtraCommands.txt --> Contains commands are utilized for disk image operations, often within virtualization contexts. The first command mounts a disk image (2023-10-10-raspios-bookworm-arm64-lite.img) to a directory (/mnt/rpi/) with specific options to handle filesystem offsets. The second command converts another disk image (2023-10-10-raspios-armhf-lite.img) from raw format to qcow2 format, saving it as 2021-10.qcow2.

7. WORKS Text Files --> starting a 64-bit QEMU Machine 
    a. WORKS.txt --> 
        - disk image --> qcow2
    b. WORKS_IMG.txt --> 
        - disk image --> raw format

8. desktop.ini --> Contains mappings for localized file names.

9. rpi-32.xml --> A blueprint to create and run a CM using QEMU. Contains a list of configuration options for defining a VM.


#Gotcha:
1. If you get "sudo: unable to resolve host (name): Name or servicec not known", do the following:
    a. enter hostname into commandline
    b. if it says none, then do the following
        i. cat /etc/hostname --> this will show you what hostname you can switch into
        ii. sudo hostname [the hostname]