#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string n;
    cin >> n;
    
    vector<int> plane(10, 0);
    for (char c : n){
        plane[c - '0']++;
    }
    plane[6] = (plane[6] + plane[9] + 1) / 2;
    plane[9] = 0;
    
    int maxN = 0;
    for (int i = 0; i < 9; i++){
        if (plane[i] > maxN) {
            maxN = plane[i];
        }
    }
    
    cout << maxN;
    
    return 0;
}