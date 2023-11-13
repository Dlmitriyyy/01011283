#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

void encrypted(string& InputText, string& EncryptedText)
{
    map <char, string> newAlphabet =
    {
        {'a', "AAAAA"}, {'b', "AAAAB"}, {'c', "AAABA"}, {'d', "AAABB"},
        {'e', "AABAA"}, {'f', "AABAB"}, {'g', "AABBA"}, {'h', "AABBB"},
        {'i', "ABAAA"}, {'j', "ABAAB"}, {'k', "ABABA"}, {'l', "ABABB"},
        {'m', "ABBAA"}, {'n', "ABBAB"}, {'o', "ABBBA"}, {'p', "ABBBB"},
        {'q', "BAAAA"}, {'r', "BAAAB"}, {'s', "BAABA"}, {'t', "BAABB"},
        {'u', "BABAA"}, {'v', "BABAB"}, {'w', "BABBA"}, {'x', "BABBB"},
        {'y', "BBAAA"}, {'z', "BBAAB"}
    };

    string TextWithoutSpaces = InputText;
    size_t PosSpace = TextWithoutSpaces.find(' ');

    while (PosSpace != string::npos)
    {
        TextWithoutSpaces.erase(PosSpace, 1);
        PosSpace = TextWithoutSpaces.find(' ', PosSpace);
    }

    cout << endl << "1) Введений текст без пробілів: " << TextWithoutSpaces << endl << endl;

    cout << "2) Введений текст без пробілів перетворений у нижній регістр: ";

    for (char a : TextWithoutSpaces)
    {
        char SmallLetters = tolower(a);
        cout << SmallLetters;
    }

    cout << endl << endl << "3) Зашифрований текст шифром Бекона: ";

    for (char a : TextWithoutSpaces)
    {
        char SmallLetters = tolower(a);

        if (isalpha(SmallLetters))
        {
            EncryptedText += newAlphabet[SmallLetters] + " ";
        }
        else
        {

        }
    }
    cout << EncryptedText;
}

void decrypted(string& EncryptedText, string& DecryptedText)
{
    map<string, char> reverseAlphabet = 
    {
        {"AAAAA", 'a'}, {"AAAAB", 'b'}, {"AAABA", 'c'}, {"AAABB", 'd'},
        {"AABAA", 'e'}, {"AABAB", 'f'}, {"AABBA", 'g'}, {"AABBB", 'h'},
        {"ABAAA", 'i'}, {"ABAAB", 'j'}, {"ABABA", 'k'}, {"ABABB", 'l'},
        {"ABBAA", 'm'}, {"ABBAB", 'n'}, {"ABBBA", 'o'}, {"ABBBB", 'p'},
        {"BAAAA", 'q'}, {"BAAAB", 'r'}, {"BAABA", 's'}, {"BAABB", 't'},
        {"BABAA", 'u'}, {"BABAB", 'v'}, {"BABBA", 'w'}, {"BABBB", 'x'},
        {"BBAAA", 'y'}, {"BBAAB", 'z'}
    };

    string EncryptedTextWithoutSpaces = EncryptedText;
    size_t PosSpace = EncryptedTextWithoutSpaces.find(' ');

    while (PosSpace != string::npos)
    {
        EncryptedTextWithoutSpaces.erase(PosSpace, 1);
        PosSpace = EncryptedTextWithoutSpaces.find(' ', PosSpace);
    }

    cout << endl << endl << "4) Розшифрований текст: ";

    for (size_t Pos = 0; Pos < EncryptedTextWithoutSpaces.length(); Pos += 5)
    {
        string PartText = EncryptedTextWithoutSpaces.substr(Pos, 5);

        if (reverseAlphabet.find(PartText) != reverseAlphabet.end())
        {
            DecryptedText += reverseAlphabet[PartText];
        }
        else
        {

        }
    }
   
    cout << DecryptedText << endl;
}

int main()
{
    system("chcp 1251 > nul");
    cout << "Цей код для шифрування введеного користувачем тексту методом Бекона, виводить покроково як відбувається шифрування, та  розшифровує у зворотньому порядку. " << endl << endl;

    string InputText, EncryptedText, DecryptedText;
    cout << "Введіть текст який треба зашифрувати: ";

    getline(cin, InputText);
    encrypted(InputText, EncryptedText);
    decrypted(EncryptedText, DecryptedText);

    return 0;
}
