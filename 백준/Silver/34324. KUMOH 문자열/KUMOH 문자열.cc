#include <bits/stdc++.h>
using namespace std;

int s_f(string &s, const string &w){
    int cnt = 0, pos = 0;
    
    while ((pos = s.find(w, pos)) != string::npos){
        cnt++, pos++;
    }
    
    return cnt;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i].resize(1000, ' ');
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        string str = "";
        int r = i, c = 0;
        
        while (r >= 0 && c < 1001){
            if (arr[r][c] != ' ') str.push_back(arr[r][c]);
            r--, c++;
        }
        
        ans += max(s_f(str, "KUMOH"), s_f(str, "HOMUK"));
    }
    
    for (int i = 1; i < 1000; i++){
        string str = "";
        int r = n - 1, c = i;
        
        while (r >= 0 && c < 1000){
            if (arr[r][c] != ' ') str.push_back(arr[r][c]);
            r--, c++;
        }
        
        ans += max(s_f(str, "KUMOH"), s_f(str, "HOMUK"));
    }
    
    cout << ans;
    
    return 0;
}