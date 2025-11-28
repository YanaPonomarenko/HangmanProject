#include <iostream>
#include "HangmanGame.h"
#include "EncryptedWord.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    EncryptedWord ew;
    if (!ew.loadWord("/Users/hevingmey/Desktop/words_encrypted.txt")) {
    cout << "Помилка: не вдалося завантажити слова!" << endl;return 1;}
    // випадкове слово для гри
    string secretWord = ew.getRandom();

    
    
    HangmanGame game;
    game.startNewGame(secretWord);
    game.start();
    game.gameInfo();
    game.finish();
    game.show();
    cout<< "ігровий час: "<<game.getTime()<<" секунд"<<endl;
    return 0;
}








