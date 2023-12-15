#
# Decrypt with private key
#
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

secret_key_file = open("secret-key.pem","r")
secret_key_data = secret_key_file.read().encode('utf-8')
secret_key_file.close()

print(secret_key_data)

private_key = rsa.PrivateKey.load_pkcs1(bytes(secret_key_data),'PEM')

file_in = open("encrypted_data.bin", "rb")
data = file_in.read()
file_in.close()

decrypted = rsa.decrypt(bytes(data),private_key)
print(decrypted)

