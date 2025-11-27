#include <string>
#include <vector>

class EncryptedWord
{
private:
    std::vector<std::string> words;  //cписок дешифрованих слів

public:
    // Завантажити слова з зашифрованого файлу
    bool loadWord(const std::string& filename);

    // отримати випадкове слово
    std::string getRandom();

    // дешифрувати слово
    std::string decryptWord(const std::string& encryptedWord);
};
