#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str, vowels = "aeiouAEIOU";

    while (true) {
        getline(cin, str);
        if (str == "#") break;

        int count = 0;
        for (char ch : str) {
            if (vowels.find(ch) != string::npos) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}