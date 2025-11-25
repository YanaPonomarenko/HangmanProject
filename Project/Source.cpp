#include <iostream>
#include "HangmanGame.h"

using namespace std;

int main() {
    setlocale(LC_ALL,"");
    cout << "*** ТЕСТУВАННЯ ***" << endl;

    HangmanGame game;
    cout << "Обєкт створено успішно" << endl;

    game.menu(1);
    cout << "Меню працює" << endl;

    game.startNewGame("apple");
    cout << "Гра розпочата" << endl;

    cout << "Приховане слово: " << game.getHiddenWord() << endl;
    cout << "Життя: " << game.getHeart() << endl;
    cout << "Стан гри відображається" << endl;

    cout << "\n*** ПЕРЕВІРКА ЛІТЕР ***" << endl;
    game.processGuess('a');
    cout << "Слово після 'a': " << game.getHiddenWord() << endl;

    game.processGuess('p');
    cout << "Слово після 'p': " << game.getHiddenWord() << endl;

    game.processGuess('x');
    cout << "Слово після 'x': " << game.getHiddenWord() << endl;
    cout << "Залишилось життів: " << game.getHeart() << endl;

    cout << "\n*** ЗАВЕРШЕННЯ ГРИ ***" << endl;
    game.processGuess('l');
    game.processGuess('e');

    cout << "Гра завершена: " << (game.isGameOver() ? "Так" : "Ні") << endl;
    cout << "Гра виграна: " << (game.isGameWon() ? "Так" : "Ні") << endl;

    return 0;
}