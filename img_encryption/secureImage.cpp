
//imports 

//the following contains the code which is used to invoke the python files, 
//it is used to generate an executable to access the CLI
#include <iostream>
#include <cstdlib> 
#include <fstream>

using namespace std;

int main() {

    string imagePath, keyPath, EncryptedImgPath, DecryptedImgPath;
    string keyGenFile = "key_gen.py";
    string encFile = "img_enc.py";
    string decFile = "img_dec.py";
    char choice;
    char option;

    cout << "----- Image Encryption and Decryption -----" << endl;
    cout << "-------------------------------------------" << endl;

    // Key management
    cout << "First Lets Get a Key" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "OPTION" << endl;
    cout << "1. Use a previous key" << endl;
    cout << "2. Generate a Key" << endl;
    cout << "Choice: ";
    cin >> option;
    cout << "-------------------------------------------" << endl;

    if (option == '1') {
        cout << "Enter the binary file path where the key is located: ";
        cin >> keyPath;
        cout << endl;

        ifstream file(keyPath);
        if (!file.good()) {
            cout << "Error: Key File not found!" << endl;
            cout << "Would you like to create a file to store the Keys? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cout << "Enter file name to save the key in: ";
                cin >> keyPath;
                system(("python " + keyGenFile + " " + keyPath + ".bin").c_str());
                cout << "Keys stored in " << keyPath << ".bin" << endl;
            }
            else{
                cout << "Ending the Progam " << endl;
                exit(1);
            }
        cout << "-------------------------------------------" << endl;
        }

        cout << "KEY FILE FOUND" << endl;
    } else if (option == '2') {
        cout << "Enter a file name to save the key in: ";
        cin >> keyPath;
        system(("python " + keyGenFile + " " + keyPath + ".bin").c_str());
        keyPath += ".bin";
        cout << "Keys stored in " << keyPath << endl;
    } 

    //This is where the code would start operations from
    while (true) {
        cout << "---- CHOOSE OPERATION ----" << endl;
        cout << "1. Encrypt Image" << endl;
        cout << "2. Decrypt Image" << endl;
        cout << "3. Exit" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "- Choice = ";
        cin >> choice;
        cout << "-------------------------------------------" << endl;

        if (choice == '1') {
            char startChar;
            cout << "Please Specify the Path to the Image: ";
            cin >> imagePath;

            ifstream file(imagePath);
            if (!file.good()) {
                cout << "Error: Image file not found!" << endl;
                system("pause");
                continue;
            }

            cout << "----------IMAGE FETCHED-----------" << endl;
            cout << "Please Specify the Encrypted Image Name: ";
            cin >> EncryptedImgPath;
            cout << endl;
            cout << "-------------------------------------------" << endl;
            cout << "Enter Y to start the Encryption process: ";
            cin >> startChar;
            cout << endl;
            if (startChar == 'y' || startChar == 'Y') {
                system(("python " + encFile + " " + keyPath + " " + imagePath + " " + EncryptedImgPath + ".bin").c_str());
                cout << "Your Encrypted Image is ready and stored in " << EncryptedImgPath << ".bin" << endl;
                cout << endl;
            } else {
                continue;
            }
        } else if (choice == '2') {
            char startChar;
            cout << "Please Specify the Path to the Encrypted Binary File: ";
            cin >> EncryptedImgPath;

            ifstream file(EncryptedImgPath);
            if (!file.good()) {
                cout << "Error: Encrypted Image file not found!" << endl;
                system("pause");
                continue;
            }

            cout << "----------IMAGE FETCHED-----------" << endl;
            cout << "Please Specify the Decrypted Image Name: ";
            cin >> DecryptedImgPath;
            cout << endl;
            cout << "-------------------------------------------" << endl;

            cout << "Enter Y to start the Decryption process: ";
            cin >> startChar;
            cout << endl;

            if (startChar == 'y' || startChar == 'Y') {
                system(("python " + decFile + " " + keyPath + " " + EncryptedImgPath + " " + DecryptedImgPath + ".jpg").c_str());
                cout << "Your Decrypted Image is ready and stored in " << DecryptedImgPath << ".jpg" << endl;
            }
        } else if (choice == '3') {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    // Adding a pause to not exit the program 
    system("pause");

    return 0;
}
