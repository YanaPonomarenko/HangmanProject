#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encryptWord(const string& originalWord) {
    string encrypted = originalWord;
    char key = 0x55;

    for (size_t i = 0; i < originalWord.length(); i++) {
        encrypted[i] = originalWord[i] ^ key;
    }

    return encrypted;
}

int main() {
    setlocale(LC_ALL, "");
    cout << "*** Утиліта для шифрування ***" << endl;

    // відкриваємо файл зі словами
    ifstream inFile("words.txt");
    ofstream outFile("words_encrypted.txt");

    if (!inFile.is_open()) {
        cerr << "Помилка файл words.txt не знайдено" << endl;
        return 1;
    }

    string word;
    int wordCount = 0;

    cout << "Процес шифрування" << endl;

    // Шифруємо кожне слово
    while (getline(inFile, word)) {
        if (!word.empty()) {
            string encryptedWord = encryptWord(word);
            outFile << encryptedWord << endl;
            cout << word << " -> " << encryptedWord << endl;
            wordCount++;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Успішно зашифровано " << wordCount << " слів" << endl;
    cout << "Створено файл: words_encrypted.txt" << endl;

    return 0;
}