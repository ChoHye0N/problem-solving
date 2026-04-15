#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;

    vector<int> arr(n);
    deque<int> dq;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() < i - l + 1)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] > arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i == n - 1)
            cout << arr[dq.front()] << '\n';
        else
            cout << arr[dq.front()] << ' ';
    }

    return 0;
}