#include <iostream>
#define STR_SIZE 21
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n;
    char str[STR_SIZE];

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> str;
        for (int j = 0; str[j] != '\0'; j++) {
            for (int k = 0; k < n; k++)
                cout << str[j];
        }
        cout << '\n';
    }

    return 0;
}