#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> schedule(n);
    for (int i = 0; i < n; i++) {
        cin >> schedule[i].first >> schedule[i].second;
    }

    sort(schedule.begin(), schedule.end(), 
         [](pair<int, int> &p1, pair<int, int> &p2) {
             if (p1.second == p2.second) return p1.first < p2.first;
             return p1.second < p2.second;
         });
    
    int count = 0, EndTime = 0;
    for (int i = 0; i < n; i++) {
        if (EndTime <= schedule[i].first) {
            EndTime = schedule[i].second;
            count++;
        }
    }
    
    cout << count << '\n';

    return 0;
}