#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long b, c, a1, a2;
    cin >> b >> c >> a1 >> a2;
    
    double ans = (b + sqrt((b * b) + c * 4)) / 2;
    
    printf("%.9f", ans);
    
    return 0;
}