#include <bits/stdc++.h>

using namespace std;

int main() {
    int cnt = 0;
    
    for (int i = 0; i < 8; i++){
        string temp;
        cin >> temp;
        
        for (int j = 0; j < 8; j++){
            if ((i + j) % 2 == 0 && temp[j] == 'F'){
                cnt++;
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}