#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;

        a > b ? cout << "Yes\n" : cout << "No\n";
    }

    return 0;
}