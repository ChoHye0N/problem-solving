#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        
        int size = sqrt(str.size());
        vector<string> arr(size, string(size, ' '));
        
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                arr[j][k] = str[j * size + k];
            }
        }
        
        for (int j = size - 1; j >= 0; j--) {
            for (int k = 0; k < size; k++) {
                cout << arr[k][j];
            }
        }
        cout << '\n';
    }
    
    return 0;
}