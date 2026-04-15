#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    /* 오일러 파이 값을 미리 계산 */
    vector<int> phi(MAX_N + 1);
    iota(phi.begin(), phi.end(), 0);

    for (int i = 2; i <= MAX_N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX_N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    vector<int> results(MAX_N + 1);
    results[0] = 1;
    for (int n = 1; n <= MAX_N; n++) {
        results[n] = results[n - 1] + 2 * phi[n];
    }

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int n;
        cin >> n;
        cout << results[n] << '\n';
    }

    return 0;
}