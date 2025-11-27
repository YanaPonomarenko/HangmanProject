#include "EncryptedWord.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string EncryptedWord::decryptWord(const string& encryptedWord) {
    string decrypted = encryptedWord;
    char key = 0x55;

    for (size_t i = 0; i < encryptedWord.length(); i++) {
        decrypted[i] = encryptedWord[i] ^ key;
    }

    return decrypted;
}

bool EncryptedWord::loadWord(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка: не вдалося відкрити файл " << filename << endl;
        return false;
    }

    string encryptedWord;
    while (getline(file, encryptedWord)) {
        if (!encryptedWord.empty()) {
            words.push_back(decryptWord(encryptedWord));
        }
    }

    file.close();

    if (words.empty()) {
        cout << "Попередження: файл не містить слів!" << endl;
        return false;
    }

    cout << "Завантажено " << words.size() << " зашифрованих слів" << endl;
    return true;
}

string EncryptedWord::getRandom() {
    if (words.empty()) {
        return "hangman";
    }

    static bool initialized = false;
    if (!initialized) {
        srand(time(0));
        initialized = true;
    }

    int randomIndex = rand() % words.size();
    return words[randomIndex];
}
