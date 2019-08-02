//Upper Case Configuration - This Works
#include <iostream>
#include<string>

using namespace std;

// Encryption Magic Vigenère cipher
string encrypt(string notSoSecureData, string key){
    int oldCharValue;
    int keyCharValue;
    int cipherCharValue;

    for(unsigned int i = 0; i < key.length(); i++){
        if(notSoSecureData[i] !=  ' '){
            oldCharValue = int(notSoSecureData[i]);
            keyCharValue = int(key[i]);

            cipherCharValue = (oldCharValue + keyCharValue) % 26;
            cipherCharValue += 'A';

            notSoSecureData[i] = char(cipherCharValue);
        }
    }
    return notSoSecureData;
}

// Decryption voodoo Vigenère cipher
string decrypt(string superSecretData, string key){
    int cipherCharValue;
    int keyCharValue;
    int originalCharValue;

    for(unsigned int i = 0; i < key.length(); i++){
        if(superSecretData[i] !=  ' '){
            cipherCharValue = int(superSecretData[i]);
            keyCharValue = int(key[i]);

            originalCharValue = (cipherCharValue - keyCharValue + 26) % 26;
            originalCharValue += 'A';

            superSecretData[i] = char(originalCharValue);
        }
    }
    return superSecretData;
}

int main()
{
// Input and generate secrets and "proper" key
// Only check being made is that the key is shorter than
// the secret data to be encrypted
    string secrets = "";
    string originalkey = "";
    string finalkey = "";
    string ciphertext = "";

    bool validInput = false;
    while(!validInput){
        cout << "Please enter the data to be encrypted." << endl;
        getline(cin, secrets);

        cout << "Please enter the key to use.  If shorter than your data, it will be repeated until length matches." << endl;
        getline(cin, originalkey);

        if( originalkey.length() > secrets.length() ){
            cout << "Please try again. Key length must not exceed data to be encrypted" << endl;
        }
        else{
            validInput = true;
        }
    }

    finalkey = originalkey;

// Ensure that lengths of key and secrets are same length
    if( originalkey.length() < secrets.length() ){
        int keylen = originalkey.length();
        for(unsigned int i = keylen; i < secrets.length(); i++){
            finalkey += finalkey[i % keylen];
        }
    }

// Make all of secrets and the key upper case to make my life easier.
    for(unsigned int i = 0; i < secrets.length(); i++){
        secrets[i] = toupper(secrets[i]);
    }
    for(unsigned int i = 0; i < finalkey.length(); i++){
        finalkey[i] = toupper(finalkey[i]);
    }

    cout << "Data to Encrypt:  " << endl;
    cout << secrets << endl << endl;

    cout << "Key to use:  " << endl;
    cout << originalkey << endl << endl;

    cout << "Key changed to match length:  " << endl;
    cout << finalkey << endl << endl;

    ciphertext = encrypt(secrets, finalkey);
    cout << "Data encrypted:  " << endl;
    cout << ciphertext << endl << endl;

    cout << "Data decrypted:  " << endl;
    cout << decrypt(ciphertext, finalkey) << endl << endl;

    return 0;
}
