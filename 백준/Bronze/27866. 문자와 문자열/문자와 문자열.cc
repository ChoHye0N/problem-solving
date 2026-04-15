#include <iostream>
#include <string>

using namespace std;

int main() {
    int idx;
    string word;
    cin >> word >> idx;
    cout << word[idx - 1] << '\n';

    return 0;
}