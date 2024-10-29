#include <iostream>
#include <string>

using namespace std;

// Функція для перевірки, чи є символ пробілом
bool isSpace(char c) {
    return c == ' ';
}

// Функція для перевірки, чи є символ знаком пунктуації
bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == ';' || c == ':' ||
        c == '!' || c == '?' || c == '-' || c == '(' ||
        c == ')' || c == '"' || c == '\'' || c == '—';
}

// Функція для обробки рядка згідно з умовою
string RemoveSpacesBeforePunctuation(const string& s) {
    string result;

    for (size_t i = 0; i < s.size(); ++i) {
        char currentChar = s[i];

        if (isSpace(currentChar)) {
            // Перевіряємо, чи наступний символ є знаком пунктуації
            if (i + 1 < s.size() && isPunctuation(s[i + 1])) {
                // Пропускаємо пробіл, якщо він передує пунктуації
                continue;
            }
        }

        result += currentChar;
    }

    return result;
}

int main() {
    string str;
    cout << "Enter a string:" << endl;
    getline(cin, str);

    string modifiedStr = RemoveSpacesBeforePunctuation(str);
    cout << "Modified string: " << modifiedStr << endl;

    return 0;
}
