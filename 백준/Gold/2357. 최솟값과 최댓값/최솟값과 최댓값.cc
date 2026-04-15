#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
using llg = long long;

llg construct_max_tree(vector<llg>& data, int start, int end, vector<llg>& maxTree, int current) {
    if (start == end) {
        maxTree[current] = data[start];
        return data[start];
    }

    int mid = start + (end - start) / 2;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    maxTree[current] = max(construct_max_tree(data, start, mid, maxTree, leftChild),
        construct_max_tree(data, mid + 1, end, maxTree, rightChild));
    return maxTree[current];
}

llg construct_min_tree(vector<llg>& data, int start, int end, vector<llg>& minTree, int current) {
    if (start == end) {
        minTree[current] = data[start];
        return data[start];
    }

    int mid = start + (end - start) / 2;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    minTree[current] = min(construct_min_tree(data, start, mid, minTree, leftChild),
        construct_min_tree(data, mid + 1, end, minTree, rightChild));
    return minTree[current];
}

llg query_max(vector<llg>& maxTree, int start, int end, int queryStart, int queryEnd, int current) {
    if (queryStart > end || queryEnd < start)
        return LLONG_MIN;
    if (queryStart <= start && queryEnd >= end)
        return maxTree[current];

    int mid = start + (end - start) / 2;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    return max(query_max(maxTree, start, mid, queryStart, queryEnd, leftChild),
        query_max(maxTree, mid + 1, end, queryStart, queryEnd, rightChild));
}

llg query_min(vector<llg>& minTree, int start, int end, int queryStart, int queryEnd, int current) {
    if (queryStart > end || queryEnd < start)
        return LLONG_MAX;
    if (queryStart <= start && queryEnd >= end)
        return minTree[current];

    int mid = start + (end - start) / 2;
    int leftChild = 2 * current + 1;
    int rightChild = 2 * current + 2;

    return min(query_min(minTree, start, mid, queryStart, queryEnd, leftChild),
        query_min(minTree, mid + 1, end, queryStart, queryEnd, rightChild));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<llg> datas(n);
    for (int i = 0; i < n; i++) {
        cin >> datas[i];
    }

    int treeSize = 2 * pow(2, ceil(log2(n))) - 1;
    vector<llg> minTree(treeSize, LLONG_MAX);
    vector<llg> maxTree(treeSize, LLONG_MIN);

    construct_min_tree(datas, 0, n - 1, minTree, 0);
    construct_max_tree(datas, 0, n - 1, maxTree, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        llg minVal = query_min(minTree, 0, n - 1, a - 1, b - 1, 0);
        llg maxVal = query_max(maxTree, 0, n - 1, a - 1, b - 1, 0);

        cout << minVal << " " << maxVal << "\n";
    }

    return 0;
}