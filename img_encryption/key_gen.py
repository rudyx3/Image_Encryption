#imports
from cryptography.fernet import Fernet;
import os;
import sys;
#function to generate a key and save it to a file
def gen_key(key_path):
    #using Fernet encryption mechanism to generate a secure key
    
    key = Fernet.generate_key()
    print(key)

    #now saving it in the binary file
    with open(key_path, 'wb') as key_file:
        key_file.write(key)
    print('Key has been saved to ' + key_path + '.')


#here in the argument all we do is pass the file name we want to save it in.
#gen_key(r'keys.bin')

#the following code is used to run it directly by the CLI
    
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python key_gen.py <key_path>")
        sys.exit(1)

    key_path = sys.argv[1]
    gen_key(key_path)