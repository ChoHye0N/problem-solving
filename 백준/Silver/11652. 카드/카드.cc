#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    map<llg, int> cards;
    for (int i = 0; i < n; i++){
        llg num;
        cin >> num;
        
        if (cards.find(num) == cards.end()) cards[num] = 1;
        else cards[num] += 1;
    }
    
    
    llg maxCount = 0, maxNum = 0;
    for (auto& card : cards){
        if (maxCount < card.second){
            maxNum = card.first;
            maxCount = card.second;
        }
    }
    
    cout << maxNum;
    
    return 0;
}