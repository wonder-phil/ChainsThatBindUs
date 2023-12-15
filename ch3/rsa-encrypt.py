#
# Encrypt with public key
#
# From: "The Chains that bind us" by Phillip G Bradford
#  https://github.com/wonder-phil/BlockchainTechNotes
#      by P. G. Bradford
#
#
# Do the following in order
#
# 1 Computer> python3 key-gen.py
# 2 Computer> python3 rsa-encrypt.py
# 3 Computer> python3 rsa-decrypt.py
#
import rsa

public_key_file = open("public-key.pem","r")
public_key_data = public_key_file.read().encode('utf-8')
public_key_file.close()

print(public_key_data)

public_key = rsa.PublicKey.load_pkcs1(bytes(public_key_data),'PEM')
data = "Greetings - Today is a great day!".encode("utf-8")

encrypted = rsa.encrypt(data,public_key)

file_out = open("encrypted_data.bin", "wb")

