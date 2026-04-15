#include <bits/stdc++.h>

using namespace std;
using llg = long long;

llg construct_tree(vector<llg>& list, int start, int end, llg* segTree, int curr){
    if (start == end){
        return segTree[curr] = list[start];
    }
    
    int mid = start + (end - start) / 2;
    int child = 2 * curr;
    
    segTree[curr] =
        construct_tree(list, start, mid, segTree, child) +
        construct_tree(list, mid + 1, end, segTree, child + 1);
    
    return segTree[curr];
}

llg query_sum(llg* segTree, int start, int end, int qS, int qE, int curr){
    if (qS > end || qE < start) return 0;
    if (qS <= start && qE >= end) return segTree[curr];
    
    int mid = start + (end - start) / 2;
    int child = 2 * curr;
    
    return query_sum(segTree, start, mid, qS, qE, child) +
           query_sum(segTree, mid + 1, end, qS, qE, child + 1);
}

void segtree_update(llg* segTree, int start, int end, int index, llg diff, int curr) {
    if (index < start || index > end) return;
    
    segTree[curr] += diff;

    if (start != end) {
        int mid = start + (end - start) / 2;
        int child = 2 * curr;
        
        segtree_update(segTree, start, mid, index, diff, child);
        segtree_update(segTree, mid + 1, end, index, diff, child + 1);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    const int MAX = 1000000;
    
    int n;
    cin >> n;
    
    vector<llg> candy(MAX + 1, 0), segTree(4 * (MAX + 1), 0);
    
    while(n--){
        int a, b, c = 0;
        cin >> a >> b;
        
        if (a == 1) {
            int left = 1, right = MAX, target = b, res = -1;
            int curr = 1, start = 1, end = MAX;
            
            while (start != end) {
                int mid = start + (end - start) / 2;
                int child = curr * 2;
                
                if (segTree[child] >= target) {
                    curr = child;
                    end = mid;
                }
                else {
                    target -= segTree[child];
                    curr = child + 1;
                    start = mid + 1;
                }
            }
            
            cout << start << '\n';
            candy[start]--;
            segtree_update(segTree.data(), 1, MAX, start, -1, 1);
        }
        else if (a == 2){
            cin >> c;
            candy[b] += c;
            segtree_update(segTree.data(), 1, MAX, b, c, 1);
        }
    }
    
    return 0;
}