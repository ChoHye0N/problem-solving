#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using llg = long long;

llg gcd(llg x, llg y) {
    return y ? gcd(y, x % y) : x;
}

llg max_gcd(const vector<llg>& arr) {
    llg max_gcd_value = 0;

    for (llg i = 0; i < arr.size(); ++i) {
        for (llg j = i + 1; j < arr.size(); ++j) {
            max_gcd_value = max(max_gcd_value, gcd(arr[i], arr[j]));
        }
    }

    return max_gcd_value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        llg num;
        vector<llg> numbers;

        while (ss >> num) {
            numbers.push_back(num);
        }

        cout << max_gcd(numbers) << '\n';
    }

    return 0;
}