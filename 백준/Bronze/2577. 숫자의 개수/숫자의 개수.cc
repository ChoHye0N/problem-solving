#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int>check(10, 0);
    string num = to_string(a * b * c);

    for (char n : num)
        check[n - '0']++;

    for (int i = 0; i < 9; i++)
        cout << check[i] << '\n';
    cout << check[9];

    return 0;
}