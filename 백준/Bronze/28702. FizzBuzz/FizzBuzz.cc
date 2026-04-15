#include <iostream>
#include <string>
#include <vector>

using namespace std;

string fizzBuzz(int n) {
    if (n % 3 == 0 && n % 5 == 0) return "FizzBuzz";
    if (n % 3 == 0) return "Fizz";
    if (n % 5 == 0) return "Buzz";
    return to_string(n);
}

bool is_number(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    vector<string> inputs(3);
    for (int i = 0; i < 3; ++i) {
        cin >> inputs[i];
    }

    int start = 1;
    for (int i = 0; i < 3; ++i) {
        if (is_number(inputs[i])) {
            start = stoi(inputs[i]) - i;
            break;
        }
    }

    cout << fizzBuzz(start + 3) << '\n';

    return 0;
}