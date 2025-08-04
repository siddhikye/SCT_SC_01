#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the message
string encrypt(string text, int shift) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char(int((c - base + shift) % 26 + base));
        } else {
            result += c; // keep non-alphabet characters unchanged
        }
    }

    return result;
}

// Function to decrypt the message
string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift); // decryption is just reverse shift
}

int main() {
    string message;
    int shift;
    char choice;

    cout << "Enter the message: ";
    getline(cin, message);
    cout << "Enter shift value (0-25): ";
    cin >> shift;

    cout << "Encrypt or Decrypt? (e/d): ";
    cin >> choice;

    if (choice == 'e' || choice == 'E') {
        cout << "Encrypted message: " << encrypt(message, shift) << endl;
    } else if (choice == 'd' || choice == 'D') {
        cout << "Decrypted message: " << decrypt(message, shift) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
