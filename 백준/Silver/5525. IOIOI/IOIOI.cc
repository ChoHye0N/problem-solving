#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ioiCounter(const string& words, int n) {
    int count = 0;
    int matchCount = 0;

    if (n == 0)
        return 0;

    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i] == 'I' && words[i + 1] == 'O' && words[i + 2] == 'I') {
            matchCount++;

            if (matchCount == n) {
                count++;
                matchCount--;
            }

            i++;
        }
        else {
            matchCount = 0;
        }
    }

    return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    string mainWords, searchWords = "IOI";
    cin >> n >> m >> mainWords;

    cout << ioiCounter(mainWords, n) << '\n';

    return 0;
}