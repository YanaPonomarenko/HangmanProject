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
    int heart;// кількість життів
    clock_t st;// початок рахунку часу
    clock_t fi;// кінець рахунку часу
    int numeric;
    //для розширення додаткові поля
    string hiddenWord;    //слово з підкресленнями для відображення
    vector<char> usedLetters; // всі літери, які вже використовувались
    int incorrect;     // лічильник невдалих спроб
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
    void start();
    void finish();

    bool check(char letter);   // перевірка чи є літера у слові

//нові методи для розширення
    void startNewGame(const string& newWord); //початок нової гри
    void updateWord(char letter); // оновлення відображення слова
    bool processGuess(char letter);     // обробка спроби гравця

    //нові геттери
    string gethWord() const { return hiddenWord; }
    vector<char> getUsedLetters() const { return usedLetters; }
    int getHeart() const { return heart; }
    int getIncorrect() const { return incorrect; }
    bool isGameWon() const { return gameWon; }
    bool isGameOver() const { return gameOver; }
    //вивід часу
    double getTime() ;
    //статистика
    void show() const;
    //aнімація
    void animation();
    //статус гри
    void gameInfo();
    //новий сеттер
    void setHeart(const int& newHeart) { heart = newHeart; }
};

