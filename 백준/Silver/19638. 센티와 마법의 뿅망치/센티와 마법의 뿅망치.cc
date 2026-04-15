#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, centi, t;
    cin >> n >> centi >> t;
    
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        pq.push(h);
    }
    
    int count = 0;
    for (int i = 0; i < t; i++) {
        int top = pq.top();
        
        if (top < centi) break;
        pq.pop();
        
        if (top == 1) {
            pq.push(1);
            break;
        }
        
        pq.push(top / 2);
        count++;
    }
    
    if (pq.top() < centi) {
        cout << "YES\n" << count;
    }
    else {
        cout << "NO\n" << pq.top();
    }

    return 0;
}