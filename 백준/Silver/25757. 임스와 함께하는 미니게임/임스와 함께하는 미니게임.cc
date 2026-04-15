#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    char game;
    cin >> n >> game;
    
    unordered_set<string> player;
    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        player.insert(name);
    }
    
    if (game == 'Y') cout << player.size();
    else if (game == 'F') cout << player.size() / 2;
    else cout << player.size() / 3;
    
    return 0;
}