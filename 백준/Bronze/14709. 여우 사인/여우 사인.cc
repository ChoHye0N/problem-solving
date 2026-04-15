#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int checkN = 0;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        
        if ((a == 1 && b == 3) || (a == 3 && b == 1)){
            checkN++;
        }
        else if ((a == 4 && b == 3) || (a == 3 && b == 4)){
            checkN++;
        }
        else if ((a == 1 && b == 4) || (a == 4 && b == 1)){
            checkN++;
        }
    }
    
    if (checkN == 3 && n == 3) cout << "Wa-pa-pa-pa-pa-pa-pow!";
    else cout << "Woof-meow-tweet-squeek";
    
    return 0;
}