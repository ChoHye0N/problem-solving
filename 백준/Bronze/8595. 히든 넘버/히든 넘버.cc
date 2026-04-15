#include <iostream>
#include <string>

using llg = long long;
using namespace std;

int main() {
    int n;
    llg sum = 0;
    cin >> n;

    string str;
    string currentNumber = "";  
    cin >> str;

    for (int i = 0; i < n; i++) {
        if (isdigit(str[i])) {
            currentNumber += str[i];
            if (currentNumber.length() == 6) {
                sum += stoll(currentNumber);
                currentNumber = "";
            }
        }
        else {
            if (!currentNumber.empty()) {
                sum += stoll(currentNumber);
                currentNumber = "";
            }
        }
    }

    if (!currentNumber.empty())
        sum += stoll(currentNumber);

    cout << sum << '\n';

    return 0;
}