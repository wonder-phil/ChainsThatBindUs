#
# From: "The Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#
#
# FIRST:
# 
# > pip3 install rsa
#  key_gen.py 
#
# Do the following in order
#
# 1 Computer> python3 key-gen.py
# 2 Computer> python3 rsa-encrypt.py
# 3 Computer> python3 rsa-decrypt.py

#
# This generates UTF-8 encoded PEM files
#

import rsa
(pub,sec) = rsa.newkeys(1024)

pub_file = open("public-key.pem","w")
sec_file = open("secret-key.pem","w")

pub_file.write(pub.save_pkcs1().decode('utf-8'))
sec_file.write(sec.save_pkcs1().decode('utf-8'))

pub_file.close()
sec_file.close()
