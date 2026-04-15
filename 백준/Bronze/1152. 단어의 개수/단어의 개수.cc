#include <iostream>
#include<cctype>

#define STR_SIZE 1000001

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char str[STR_SIZE];
    int wordCount = 0;
    bool isWord = false;

    cin.getline(str, STR_SIZE);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            if (isWord)
                isWord = false;
        }
        else {
            if (!isWord) {
                isWord = true;
                wordCount++;
            }
        }
    }

    cout << wordCount << '\n';

    return 0;
}