#include <string>
#include <iostream>
using namespace std;


class Hangman
{
    
private:
// слово для виведення
    string word="cat";// тестове слово
// буква
    char letter;
// лічильник спроб
    int counter;
// виклик меню
    int numeric;
//кількість життя
    int heart=3;

public:
    Hangman()=default;
    Hangman(string word,char letter,int counter,int numeric)
    {
        this->word=word;
        this->letter=letter;
        this->counter=counter;
        this->numeric=numeric;
    }
    // гетери та сетери
    
    void setNumeric(const int& NewNumeric){numeric=NewNumeric;}
    
    string getWord() const{return word;}
    void setWord(const string& newWord){word=newWord;}
    
    char getLetter()const{return letter;}
    void setLetter(const char& NewLetter){letter=NewLetter;}
    
    int getCounter()const{return counter;}
    void setCounter(const int& Newcounter){counter=Newcounter;}
    
    // пошук схожої букви, повинно повертати зашифроване слово
    bool check(char letter){
        bool find=false;
        for (int i=0;i<word.size();i++){
            
            if (word[i]==letter){find=true;}}
        
        return find;//повертає true коли знайшло
    }
       // меню гри . краще тут залишити, щоб був охайний main
    int menu (int numeric)
        {
            if(numeric==1)
            cout<<"***** START GAME *****"<<endl;
        
            else if (numeric==2)
            cout<<"****** EXIT ******"<<endl;
            else
             cout<<"try again!!"<<endl;
            
            return numeric;
        }
    
    
    
    
    
};
// test
int main() {
    Hangman game;

  

    char letter;
    cout << "enter letter: ";
    cin >> letter;

    if (game.check(letter)) {
        cout << "діло буде " << endl;
    } else {
        cout << "Упс" << endl;
    }

    return 0;
}
