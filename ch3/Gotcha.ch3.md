# Gotchas Chapter 3
#
# From: "Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#

## Some common gotchas

0. The rsa-encrypt.py and rsa-decrypt.py are not working
   Try running the programs in this order - top down
   1 Computer> python3 key-gen.py
   2 Computer> python3 rsa-encrypt.py
   3 Computer> python3 rsa-decrypt.py
   
   Check that both files public_key.pem and secret_key.pem are genrated by key-gen.py
   These files should be human readable.  These are UTF-8 translatios of PEM files.
   secret_key.pem starts with:
   -----BEGIN RSA PRIVATE KEY-----
   public-key.pem starts with:
   -----BEGIN RSA PUBLIC KEY-----
   
1.
2.
	
3. 

