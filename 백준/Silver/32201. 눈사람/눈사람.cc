#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    llg temp;
    unordered_map<llg, llg> ranks;
    for (int i = 0; i < n; i++){
        cin >> temp;
        ranks[temp] = i;
    }
    
    vector<vector<llg>> sortedRanks(n, vector<llg>(3));
    for (int i = 0; i < n; i++){
        cin >> temp;
        sortedRanks[i] = { temp, ranks[temp], ranks[temp] - i };
    }
    
    llg maxRank = sortedRanks[0][2];
    for (int i = 1; i < n; i++){
        if (sortedRanks[i][2] > maxRank) maxRank = sortedRanks[i][2];
    }
    
    for (int i = 0; i < n; i++){
        if (sortedRanks[i][2] == maxRank) cout << sortedRanks[i][0] << ' ';
    }
    
    return 0;
}