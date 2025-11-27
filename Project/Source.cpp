#include <iostream>
#include "HangmanGame.h"
#include "EncryptedWord.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    EncryptedWord ew;
    if (!ew.loadWord("words_encrypted.txt")) {
        cout << "Помилка: не вдалося завантажити слова!" << endl;
        return 1;
    }

    // випадкове слово для гри
    string secretWord = ew.getRandom();

    HangmanGame game;
    game.startNewGame(secretWord);

    cout << "*** Вгадайте слово! ***" << endl;

    while (!game.isGameOver() && !game.isGameWon()) {
        cout << "\nПоточне слово: " << game.getHiddenWord() << endl;
        cout << "Залишилось життів: " << game.getHeart() << endl;
        cout << "Введіть букву: ";
        char guess;
        cin >> guess;

        game.processGuess(guess);

        if (game.isGameWon()) {
            cout << "\nВітаємо! Ви відгадали слово: " << secretWord << endl;
            break;
        }
        else if (game.isGameOver()) {
            cout << "\nГру завершено! Загадане слово було: " << secretWord << endl;
            break;
        }
    }

    return 0;
}




/*int main() {
    setlocale(LC_ALL, "");

    cout << "*** ТЕСТУВАННЯ HangmanGame + EncryptedWord ***" << endl;

    // Створюємо об'єкт EncryptedWord
    EncryptedWord ew;
    if (!ew.loadWord("words_encrypted.txt")) {
        cout << "Помилка: не вдалося завантажити слова!" << endl;
        return 1;
    }

    // випадкове слово
    string word = ew.getRandom();
    cout << "Випадкове слово для гри: " << word << endl;

    // Створюємо обєкт гри
    HangmanGame game;
    cout << "Об'єкт створено успішно" << endl;

    game.startNewGame(word);  // запускаємо гру з випадковим словом

    cout << "Приховане слово: " << game.getHiddenWord() << endl;
    cout << "Життя: " << game.getHeart() << endl;

    // Тест кількох введених букв
    game.processGuess('a');
    cout << "Слово після 'a': " << game.getHiddenWord() << endl;

    game.processGuess('p');
    cout << "Слово після 'p': " << game.getHiddenWord() << endl;

    game.processGuess('x');
    cout << "Слово після 'x': " << game.getHiddenWord() << endl;
    cout << "Залишилось життів: " << game.getHeart() << endl;

    // Завершуємо гру, вводимо правильні літери
    for (char c : word) {
        game.processGuess(c);
    }

    cout << "Гра завершена: " << (game.isGameOver() ? "Так" : "Ні") << endl;
    cout << "Гра виграна: " << (game.isGameWon() ? "Так" : "Ні") << endl;

    return 0;
}*/


/*int main() {
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
}*/