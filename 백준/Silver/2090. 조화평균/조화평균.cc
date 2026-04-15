#include <bits/stdc++.h>

using namespace std;
using llg = long long;

llg  gcd(llg a, llg b){
    return b ? gcd(b, a % b) : a;
}

llg lcm(llg a, llg b){
    return (a / gcd(a, b)) * b;
}

int main(){
    int n;
    cin >> n;
    
    vector<llg> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    llg lcmNum = arr[0], ans = 0;
    for (int i = 1; i < n; i++){
        lcmNum = lcm(lcmNum, arr[i]);
    }
    
    for (int i = 0; i < n; i++){
        if (arr[i] == 1) ans += lcmNum;
        else ans += lcmNum / arr[i];
    }
    
    llg temp = gcd(ans, lcmNum);
    cout << lcmNum / temp << '/' << ans / temp;
    
    return 0;
}