#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // 우선순위 큐 라이브러리 사용
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        minHeap.push(temp);
    }
    
    long long total = 0;
    
    while (minHeap.size() > 1) {
        int n1 = minHeap.top();
        minHeap.pop();
        int n2 = minHeap.top();
        minHeap.pop();
        
        total += n1 + n2;
        minHeap.push(n1 + n2);
    }
    
    cout << total << '\n';
    
    return 0;
}