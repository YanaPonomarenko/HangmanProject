#pragma once
#include <iostream>
#include <vector>

using namespace std;

class HangmanGame
{
private:
    string word;           //слово для вгадування (оригінальне)
    char letter;               // поточна літера, яку вводить гравець
    int counter;               // лічильник спроб (загальна кількість)
    int numeric;               // вибір у меню
    int heart;                 // кількість життів
//для розширення додаткові поля
    string hiddenWord;    //слово з підкресленнями для відображення
    vector<char> usedLetters; // всі літери, які вже використовувались
    int incorrectAttempts;     // лічильник невдалих спроб
    bool gameWon;              // чи виграв гравець
    bool gameOver;             // чи гра завершена

public:
    HangmanGame();
    HangmanGame(string word, char letter, int counter, int numeric);

    void setNumeric(const int& NewNumeric);
    string getWord() const;
    void setWord(const string& newWord);
    char getLetter() const;
    void setLetter(const char& NewLetter);
    int getCounter() const;
    void setCounter(const int& Newcounter);

    bool check(char letter);   // перевірка чи є літера у слові
    int menu(int numeric);     // відображення меню

//нові методи для розширення
    void startNewGame(const string& newWord); //початок нової гри
    void updateHiddenWord(char letter); // оновлення відображення слова
    bool processGuess(char letter);     // обробка спроби гравця

    //нові геттери
    string getHiddenWord() const { return hiddenWord; }
    vector<char> getUsedLetters() const { return usedLetters; }
    int getHeart() const { return heart; }
    int getIncorrectAttempts() const { return incorrectAttempts; }
    bool isGameWon() const { return gameWon; }
    bool isGameOver() const { return gameOver; }

    //новий сеттер
    void setHeart(const int& newHeart) { heart = newHeart; }
};

