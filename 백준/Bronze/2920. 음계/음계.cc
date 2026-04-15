#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ascend = 0, descend = 0;
    vector<int> arr(8, 0);
    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    int val = arr[0];
    for (int i = 1; i < 8; i++) {
        if (val < arr[i]) ascend++;
        if (val > arr[i]) descend++;
        val = arr[i];
    }

    if (ascend == 7) cout << "ascending" << '\n';
    else if (descend == 7) cout << "descending" << '\n';
    else cout << "mixed" << '\n';

    return 0;
}