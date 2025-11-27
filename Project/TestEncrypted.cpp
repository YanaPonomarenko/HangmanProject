/*#include <iostream>
#include "EncryptedWord.h"

using namespace std;

void testEncryptedWord() {
    setlocale(LC_ALL, "");
    cout << "*** Тестування EncryptedWord ***" << endl;

    EncryptedWord encryptedWord;

    if (encryptedWord.loadWord("words_encrypted.txt")) { 
        cout << "Зашифровані слова завантажено успішно" << endl;

        cout << "\nВипадкові слова:" << endl;
        for (int i = 0; i < 5; i++) {
            string word = encryptedWord.getRandom(); 
            cout << "Слово " << i + 1 << ": " << word << endl;
        }
    }
    else {
        cout << "Помилка завантаження зашифрованих слів" << endl;
    }
}
int main() {
    testEncryptedWord();
    return 0;
}*/