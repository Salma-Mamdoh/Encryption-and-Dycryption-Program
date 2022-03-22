#include<iostream>
using namespace std;
#include<string.h>
#include<algorithm>
#include<string>
#include<cstring>
int main()
{
    string message;
    int  answer;

    cout << "Hallo in my program : Atbash chiper :" << endl;
    cout << "if you want to make encyrption Please enter 1\nif you want to make decryption please enter 2:" << endl;
    cin >> answer;
    
    
    // the encryption part 
    if (answer == 1) {   // check if the answer want to encrypt oe decrypt 

       cout << "Enter the message you want to encrypt:";
       cin.ignore();
       getline(cin,message);  // to get all the message even after the space
       transform(message.begin(), message.end(), message.begin(), ::toupper); // to transform to uppercase

        string charater = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string reverse_character = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

        
        string ency_text = ""; // empty string to add the encrepytion text
        for (int i = 0; i < message.length(); i++) // looping in the massage that user enter
        {
            if (message[i] == 32) {
                ency_text += " ";
                // 32 equal space in ascii
                // if i == space add space to ency_text
            }
            else {
                for (int j = 0; j < charater.length(); j++) {
                    if (message[i] == charater[j]) {
                        ency_text += reverse_character[j];
                    }//if j == charter from A to Z replace it by its reverse in string reverse character
                }

            }
        }


        cout << "The encryption of the message is :" << ency_text << endl;
    }
    
    // the decryption part 
    else if (answer == 2) { // check the amswer of the user 
       cout << "Enter the message you want to decrypt:";
       cin.ignore();
       getline(cin, message);  // to get all the message even after the space
       
       transform(message.begin(), message.end(), message.begin(), ::toupper); // to transform to uppercase

        string charater2 = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
        string reverse_character2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        string decrypt_text = ""; // empty string to add the decription  text
        for (int i = 0; i < message.length(); i++) // looping in the massage that user enter
        {
            if (message[i] == 32) {
                decrypt_text += " ";
                // 32 equal space in ascii
                // if i == space add space to decrpt_text
            }
            else {
                for (int j = 0; j < charater2.length(); j++) {
                    if (message[i] == charater2[j]) {
                        decrypt_text += reverse_character2[j];
                    }//if j == charter from zto a  replace it by its reverse in string reverse character
                }

            }
        }


        cout << "The decryption of the message is :" << decrypt_text << endl;
    }
    else { // if the answer not 1 or 2 make the user to try again 
        cout << "Invalid operation please try again :)" << endl;
    }
    }

