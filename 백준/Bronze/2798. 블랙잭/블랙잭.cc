#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cardNum, target, maxSum = 0;
    cin >> cardNum >> target;

    vector<int> cards(cardNum);
    for (int i = 0; i < cardNum; i++)
        cin >> cards[i];

    for (int i = 0; i < cardNum - 2; i++)
        for (int j = i + 1; j < cardNum - 1; j++)
            for (int k = j + 1; k < cardNum; k++) {
                int currentSum = cards[i] + cards[j] + cards[k];

                if (currentSum <= target) {
                    maxSum = max(maxSum, currentSum);
                }
            }

    cout << maxSum << '\n';

    return 0;
}