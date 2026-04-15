#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;

int f(int n){
    int sum = n;
    while (n > 0){
        sum = sum + n % 10;
        n = n / 10;
    }
    
    return sum;
}

int main() 
{
    vector<bool> arr(MAX, false);
    for (int i = 0; i < MAX; i++){
        int num = f(i);
        
        if (num < MAX){
            arr[num] = true;
        }
    }
    
    for (int i = 1; i < MAX; i++){
        if (!arr[i]) cout << i << "\n";
    }
    
    return 0;
}