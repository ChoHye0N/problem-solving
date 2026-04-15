#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> stack;

    for (int i = str.size() - 1; i >= 0; i--) {
        char c = str[i];
        
        if (c == 'x') stack.push_back(0);
        else if (c == 'g') {
            if (stack.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            int value = stack.back();
            stack.pop_back();
            stack.push_back(value + 1);
        }
        else if (c == 'f') {
            if (stack.size() < 2) {
                cout << -1 << '\n';
                return 0;
            } 
            int value1 = stack.back();
            stack.pop_back();
            int value2 = stack.back();
            stack.pop_back();
            
            stack.push_back(min(value1, value2));
        }
        else {
            cout << -1 << '\n';
            return 0;
        }
    }

    if (stack.size() == 1) {
        cout << stack.back() << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}