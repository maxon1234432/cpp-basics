#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

bool IsVowel(char letter);
string RemoveSurroundingPuncts(string word, size_t& word_len);

int main()
{
    ifstream fin("text.txt");
    if (!fin)
    {
        cout << "File \"text.txt\" not found.";
        return 1;
    }

    string word;
    while (fin >> word)
    {
        size_t word_len = word.length();
        word = RemoveSurroundingPuncts(word, word_len);
        if (IsVowel(word[0]) && IsVowel(word[word_len - 1]))
            cout << word << endl;
    }

    fin.close();
    return 0;
}

string RemoveSurroundingPuncts(string word, size_t& word_len)
{
    // Before the word.
    int i = 0;
    while (ispunct(word[i]))
    {
        i++;
        word_len--;
    }
    word = word.substr(i, word_len);

    // After the word.
    i = word_len - 1;
    while (ispunct(word[i]))
    {
        i--;
        word_len--;
    }
    word = word.substr(0, word_len);

    return word;
}

bool IsVowel(char letter)
{
    letter = tolower(letter, locale());
    char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
    for (int i = 0; i < 5; i++)
        if (letter == vowels[i])
            return 1;
    return 0;
}