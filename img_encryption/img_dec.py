
#imports
import sys
from cryptography.fernet import Fernet 
from PIL import Image
import io

#function to decrypt the saved image
def img_decryption(key_path, enc_image_path, dec_image_path):

    with open(key_path, 'rb') as key_file:
        key = key_file.read()
        print('Decrypted using this key: ' +  key.decode('utf-8') + " .")
    
    cipher = Fernet(key)

    #loading the binary encrypted image file
    with open(enc_image_path, 'rb') as file:
        enc_bytes = file.read()
    
    #following a procedure to decrypt the image
    dec_bytes = cipher.decrypt(enc_bytes)
    img_bytes_arr = io.BytesIO(dec_bytes)
    image = Image.open(img_bytes_arr)

    #Saving the image file to the directory specified
    image.save(dec_image_path)
    print('~~~~~~~ Decryption Successful ~~~~~~~');



#arguments variable to change
#img_decryption(r'keys.bin' , 'enc_img.bin' , 'dec_img.jpg')

#the following code is used to run it directly by the CLI
if __name__ == "__main__" : 

    key_path = sys.argv[1]
    enc_img_path = sys.argv[2]
    dec_img_path = sys.argv[3]
    img_decryption(key_path , enc_img_path , dec_img_path)
    