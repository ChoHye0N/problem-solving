#include <iostream>
#include <vector>

using namespace std;
using llg = long long;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

llg lcm(llg a, llg b) {
    return (a / gcd(a, b)) * b;
}

llg lcm_of_array(vector<llg>& arr) {
    llg result = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<llg> arr(n-2);

    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];
    }

    cout << lcm_of_array(arr) << '\n';

    return 0;
}