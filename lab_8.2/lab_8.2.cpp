#include <iostream>
#include <string>

using namespace std;

// ������� ��� ��������, �� � ������ �������
bool isSpace(char c) {
    return c == ' ';
}

// ������� ��� ��������, �� � ������ ������ ����������
bool isPunctuation(char c) {
    return c == '.' || c == ',' || c == ';' || c == ':' ||
        c == '!' || c == '?' || c == '-' || c == '(' ||
        c == ')' || c == '"' || c == '\'' || c == '�';
}

// ������� ��� ������� ����� ����� � ������
string RemoveSpacesBeforePunctuation(const string& s) {
    string result;

    for (size_t i = 0; i < s.size(); ++i) {
        char currentChar = s[i];

        if (isSpace(currentChar)) {
            // ����������, �� ��������� ������ � ������ ����������
            if (i + 1 < s.size() && isPunctuation(s[i + 1])) {
                // ���������� �����, ���� �� ������ ����������
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
