#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    string year;
    int n;
    cin >> year >> n;
    
    vector<string> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    llg maxS = 0;
    string ans;
    
    for (int i = 0; i < n; i++) {
        string date = arr[i];
        llg yearS = 0, monthS = 0, dayS = 0;
        
        for (int j = 0; j < 8; j++) {
            int diff = (year[j] - '0') - (date[j] - '0');
            int sq = diff * diff;
            
            if (j < 4) yearS += sq;
            else if (j < 6) monthS += sq;
            else dayS += sq;
        }
        
        llg value = yearS * monthS * dayS;
        
        if (value > maxS || (value == maxS && date < ans)) {
            maxS = value;
            ans = date;
        }
    }
    
    cout << ans;
    
    return 0;
}