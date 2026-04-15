#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> cards(n);
    for(int i = 0; i < n; i++){
        cin >> cards[i].first >> cards[i].second;
    }
    
    for(int i = 0; i < m; i++){
        int command;
        cin >> command;
        
        for(int j = 0; j < n; j++){
            if(cards[j].first <= command)
                swap(cards[j].first, cards[j].second);
        }
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += cards[i].first;
    }
    
    cout << sum << '\n';

    return 0;
}