
#importing all necessary libraries

from PIL import Image;
from cryptography.fernet import Fernet
import sys;
import io;

def img_encryption(key_file_path , image_path , enc_image_path):
    
    #reading the file to fetch the key
    with open(key_file_path , 'rb') as key_file:
        key = key_file.read()
       #print(key)

    #This creates a cipher object 
    cipher = Fernet(key)

    #now we load the image 
    with Image.open(image_path) as image:
        img = image.convert('RGB')
        img_bytes_array = io.BytesIO()
        img.save(img_bytes_array, format = 'JPEG')
        img_bytes = img_bytes_array.getvalue()

    #performing encryption to the img_bytes objects
    enc_bytes = cipher.encrypt(img_bytes)

    #This will write encrypted bytes to a binary file and save it there
    with open(enc_image_path , "wb") as file:
        file.write(enc_bytes)

    print('~~~~~~~ Encryption Successful ~~~~~~~');

#arguments variable to change
#img_encryption(r'keys.bin' , '../img_to_be_encrypted.jpg' , 'enc_img.bin')

#the following code is used to run it directly by the CLI

if __name__ == "__main__" : 

    key_path = sys.argv[1]
    image_path = sys.argv[2]
    enc_img_path = sys.argv[3]
    img_encryption(key_path , image_path , enc_img_path)
    