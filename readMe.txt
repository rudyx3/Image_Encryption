
SYMMETRIC IMAGE ENCRYPTION USING FERNET 
------------------------------------------------------------------------------------------------------
A Command-Line tool designed for users to perform a simple image symmetric encryption and decryption with basic key management features combined with an easier to use interaction method.
The following section covers an explanation about each of the files.
------------------------------------------------------------------------------------------------------
•	Key Generation (key_gen.py): Generates a cryptographic key using the Fernet method, crucial for the encryption and decryption processes.
•	Encryption (img_enc.py): Handles image loading, conversion to byte format, encryption using the Fernet method, and saving the encrypted data.
•	Decryption (img_dec.py): Reverses the encryption process to restore the original image from encrypted data.
•	C++ Component (secureImage.cpp): Provides a CLI that integrates with the Python scripts, facilitating seamless user interactions for performing encryption and decryption tasks.

This section covers how to use the tool effectively.
------------------------------------------------------------------------------------------------------
This is a step-by-step instruction or guide 
to use the functionality.

Firstly open the terminal and run the following commands to
installing the necessary libraries:

"pip install pillow"
"pip install cryptography"

||||||||||||||||||||||||||||||||||||||||||||||||||||||
***Steps to perform the encryption and decryption***
||||||||||||||||||||||||||||||||||||||||||||||||||||||

THE ENCRYPTION AND DECRYPTION IS CARRIED OUT THROUGH PYTHON FILES:
THE USER INTERACTION IS PERFORMED USING THE COOMMAND LINE INTERFACE (CLI)
FIRSTLY: 

1. Run the executable file name "secureImage.exe"
2. Follow the instructions from the command line Interface to use an existing Key OR generate a key.
3. Enter 1 to use an existing key binary file.
4. Enter 2 to generate a new key file. 

|||||||||||||||||||||||||||||
------ HOW TO ENCRYPT -------
|||||||||||||||||||||||||||||


1. Select the encryption option and specify the image path.
for example: '../img_to_be_encrypted.jpg'

2. Next specify the File name for saving it in the encryption file.
3. Follow the CLI interface and then enter "y" or "Y" to start the encryption process.

|||||||||||||||||||||||||||||
------ HOW TO DECRYPT -------
|||||||||||||||||||||||||||||


1. Select the decryption option and specify the encrypted image name/path.
2. Next specify the File name for the decrypted image.
3. Follow the CLI interface and then enter "y" or "Y" to start the decryption process.

TO EXIT CHOOSE 3

