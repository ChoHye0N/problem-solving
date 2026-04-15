#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string word;
    cin >> word;

    vector<int>check(26, -1);

    for (int i = 0; word[i]; i++)
        if (check[word[i] - 'a'] < 0)
            check[word[i] - 'a'] = i;

    for (int i = 0; i < check.size() - 1; i++)
        cout << check[i] << ' ';
    cout << check[check.size() - 1];

    return 0;
}