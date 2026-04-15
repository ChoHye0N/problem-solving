#include <iostream>
#include <vector>
#include <cmath>

typedef long long llg;
using namespace std;

llg construct_tree(vector<llg>& list, int start, int end, llg* segTree, int current) {
    if (start == end) {
        segTree[current] = list[start];
        return list[start];
    }
    int mid = start + (end - start) / 2;
    int child = 2 * current;
    segTree[current] = construct_tree(list, start, mid, segTree, child + 1) +
        construct_tree(list, mid + 1, end, segTree, child + 2);

    return segTree[current];
}

llg query_sum(llg* segTree, int start, int end, int q_s, int q_e, int current) {
    if (q_s > end || q_e < start) return 0;
    if (q_s <= start && q_e >= end) return segTree[current];

    int mid = start + (end - start) / 2;
    int child = 2 * current;

    return query_sum(segTree, start, mid, q_s, q_e, child + 1) +
        query_sum(segTree, mid + 1, end, q_s, q_e, child + 2);
}

void segtree_update(llg* segTree, int start, int end, int index, llg diffVal, int current) {
    if (index > end || index < start) return;
    segTree[current] = segTree[current] + diffVal;

    if (start != end) {
        int mid = start + (end - start) / 2;
        int child = 2 * current;
        segtree_update(segTree, start, mid, index, diffVal, child + 1);
        segtree_update(segTree, mid + 1, end, index, diffVal, child + 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    llg numSize, changeSize, sumSize;
    cin >> numSize >> changeSize >> sumSize;

    int height = (int)ceil(log2(numSize));
    int arrSize = 2 * (int)pow(2, height) - 1;

    vector<llg> numArr(numSize, 0);
    llg* segTree = new llg[arrSize]();

    for (int i = 0; i < numSize; i++)
        cin >> numArr[i];

    construct_tree(numArr, 0, numSize - 1, segTree, 0);

    for (int i = 0; i < changeSize + sumSize; i++) {
        llg op, n1, n2;
        cin >> op >> n1 >> n2;

        if (op == 1) {
            llg diff = n2 - numArr[n1 - 1];
            numArr[n1 - 1] = n2;
            segtree_update(segTree, 0, numSize - 1, n1 - 1, diff, 0);
        }
        else if (op == 2) {
            cout << query_sum(segTree, 0, numSize - 1, n1 - 1, n2 - 1, 0) << '\n';
        }
    }

    delete[] segTree;
    return 0;
}