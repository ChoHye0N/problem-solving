#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string a, b;
    cin >> a >> b;
    
    int minDiff = a.size();
    
    for (int i = 0; i <= b.size() - a.size(); i++) {
        int diff = 0;
        
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[i + j]) diff++;
        }
        if (diff < minDiff) minDiff = diff;
    }
    
    cout << minDiff << '\n';
    
    return 0;
}