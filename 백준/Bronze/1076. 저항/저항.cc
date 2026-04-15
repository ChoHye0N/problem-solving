#include <bits/stdc++.h>

using namespace std;

int main() 
{
    unordered_map<string, int> um = {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4},
        {"green", 5}, {"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9}
    };

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    long long ans = (um[s1] * 10 + um[s2]) * pow(10, um[s3]);

    cout << ans;
    
    return 0;
}