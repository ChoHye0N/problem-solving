#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string num;
    cin >> num;
    
    int count = 0;
    while (num.size() > 1){
        int total = 0;
        
        for (char n : num){
            total += n - '0';
        }
        count++;
        
        num = to_string(total);
    }
    
    cout << count << '\n';
    cout << (stoi(num) % 3 == 0 ? "YES" : "NO");
    
    return 0;
}