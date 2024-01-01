#
# From: "Chains that bind us" by Phillip G. Bradford
#  https://github.com/wonder-phil/ChainsThatBindUs
#     
import paramiko

class RPI_5023_Mine():
    def __init__(self,difficulty):
        RPI_1 = paramiko.SSHClient()

        RPI_1.set_missing_host_key_policy(paramiko.AutoAddPolicy())

        RPI_1.connect(hostname='localhost',username='pi',port=5023,password="raspberry")
        stdin,stdout,stderr=RPI_1.exec_command('python3 testMine.py ' + str(difficulty))

        output = stdout.readlines()
        for items in output:
            print("RPI_1:" + items)

        error = stderr.readlines()
        for items in error:
            print("error - RPI_1:" + items)

        RPI_1.close()


rpi_1 = RPI_5023_Mine(3)
