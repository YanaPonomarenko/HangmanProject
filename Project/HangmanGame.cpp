#include "HangmanGame.h"
#include <iostream>

using namespace std;

// допоміжна функція для перетворення в нижній регістр
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

HangmanGame::HangmanGame()
    : word(""), letter(' '), counter(0), numeric(0), heart(3),
    hiddenWord(""), incorrectAttempts(0), gameWon(false), gameOver(false)
{
    // word залишається порожнім ,буде встановлено через startNewGame()
}

HangmanGame::HangmanGame(string word, char letter, int counter, int numeric)
    : word(word), letter(letter), counter(counter), numeric(numeric),
    heart(5), hiddenWord(""), incorrectAttempts(0), gameWon(false), gameOver(false)
{
}

void HangmanGame::setNumeric(const int& NewNumeric) {
    numeric = NewNumeric;
}

string HangmanGame::getWord() const {
    return word;
}

void HangmanGame::setWord(const string& newWord) {
    word = newWord;
}

char HangmanGame::getLetter() const {
    return letter;
}

void HangmanGame::setLetter(const char& NewLetter) {
    letter = NewLetter;
}

int HangmanGame::getCounter() const {
    return counter;
}

void HangmanGame::setCounter(const int& Newcounter) {
    counter = Newcounter;
}

bool HangmanGame::check(char letter) {
    //перевіряємо чи слово не порожнє
    if (word.empty()) {
        return false;
    }

    bool find = false;
    char lowerLetter = toLower(letter);

    for (int i = 0; i < word.size(); i++) {
        if (toLower(word[i]) == lowerLetter) {
            find = true;
        }
    }

    return find;
}

int HangmanGame::menu(int numeric) {
    if (numeric == 1) {
        cout << "***** ПОЧАТОК ГРИ *****" << endl;
    }
    else if (numeric == 2) {
        cout << "****** ВИХІД ******" << endl;
    }
    else {
        cout << "Спробуйте ще раз!!" << endl;
    }

    return numeric;
}

void HangmanGame::startNewGame(const string& newWord) {
    // перевіряємо чи слово не порожнє
    if (newWord.empty()) {
        cout << "Помилка: спробували почати гру з порожнім словом!" << endl;
        return;
    }

    word = newWord;

    // створюємо приховане слово з підкресленнями
    hiddenWord = "";
    for (size_t i = 0; i < word.length(); i++) {
        hiddenWord += "_ ";
    }
    // видалення останнього пробілу
    if (!hiddenWord.empty()) {
        hiddenWord.pop_back();
    }

    usedLetters.clear();//очистка використаних літер

    //скидаємо лічильники
    counter = 0;
    incorrectAttempts = 0;
    heart = 5;
    gameWon = false;
    gameOver = false;

    cout << "Гра розпочата! Слово має " << word.length() << " літер." << endl;
}

void HangmanGame::updateHiddenWord(char letter) {
    // перевіряємо чи слово не порожнє
    if (word.empty()) {
        return;
    }

    // створюємо нове приховане слово
    string newHiddenWord = "";
    char lowerLetter = toLower(letter);

    for (size_t i = 0; i < word.length(); i++) {
        if (toLower(word[i]) == lowerLetter) {
            newHiddenWord += word[i];
        }
        else {
            size_t pos = i * 2;
            if (pos < hiddenWord.length() && hiddenWord[pos] != '_') {
                newHiddenWord += hiddenWord[pos];
            }
            else {
                newHiddenWord += '_';
            }
        }
        newHiddenWord += " ";
    }

    if (!newHiddenWord.empty()) {
        newHiddenWord.pop_back();
    }

    hiddenWord = newHiddenWord;
}

bool HangmanGame::processGuess(char letter) {
    // перевірка чи гра взагалі розпочата
    if (word.empty()) {
        cout << "Помилка: гра не розпочата! Викличте startNewGame() спочатку." << endl;
        return false;
    }

    this->letter = letter;
    char lowerLetter = toLower(letter);

    // перевірка чи не використовувалась вже ця літера
    bool alreadyUsed = false;
    for (size_t i = 0; i < usedLetters.size(); i++) {
        if (toLower(usedLetters[i]) == lowerLetter) {
            alreadyUsed = true;
            break;
        }
    }

    if (alreadyUsed) {
        cout << "Ви вже використовували літеру '" << letter << "'!" << endl;
        return false;
    }

    // Додаємо літеру до списку використаних
    usedLetters.push_back(letter);
    counter++;

    bool letterFound = check(letter);

    if (letterFound) {
        cout << "Вітаю! Літера '" << letter << "' є в слові!" << endl;
        updateHiddenWord(letter);
    }
    else {
        cout << "На жаль, літери '" << letter << "' немає в слові." << endl;
        heart--;
        incorrectAttempts++;
    }

    // перевірка завершення гри
    gameWon = true;
    for (size_t i = 0; i < hiddenWord.length(); i += 2) {
        if (hiddenWord[i] == '_') {
            gameWon = false;
            break;
        }
    }

    bool gameLost = (heart <= 0);
    gameOver = gameWon || gameLost;

    if (gameWon) {
        cout << "ВІТАЮ! ВИ ВГАДАЛИ СЛОВО: " << word << endl;
    }
    else if (gameLost) {
        cout << "ГРА ЗАВЕРШЕНА! Слово було: " << word << endl;
    }

    return letterFound;
}