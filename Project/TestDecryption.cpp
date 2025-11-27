/*#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string decryptWord(const string& encryptedWord) {
    string decrypted = encryptedWord;
    char key = 0x55;

    for (size_t i = 0; i < encryptedWord.length(); i++) {
        decrypted[i] = encryptedWord[i] ^ key;
    }

    return decrypted;
}

int main() {
    setlocale(LC_ALL, "");
    cout << "=== Тест дешифрування ===" << endl;

    ifstream file("words_encrypted.txt");
    if (!file.is_open()) {
        cout << "Не вдалося відкрити words_encrypted.txt" << endl;
        return 1;
    }

    string encryptedWord;
    cout << "Зашифроване -> Розшифроване" << endl;
    cout << "---------------------------" << endl;

    while (getline(file, encryptedWord)) {
        if (!encryptedWord.empty()) {
            string decrypted = decryptWord(encryptedWord);
            cout << encryptedWord << " -> " << decrypted << endl;
        }
    }

    file.close();
    cout << "Перевірка пройдена" << endl;

    return 0;
}*/