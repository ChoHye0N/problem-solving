#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, p;
	int clothesCount = 0;
	vector<int> clothesList(6);
	cin >> n;

	for (int i = 0; i < 6; i++)
		cin >> clothesList[i];

	cin >> t >> p;

	for (int i = 0; i < 6; i++)
		clothesCount += (clothesList[i] + t - 1) / t;

	cout << clothesCount << '\n' << n / p << ' ' << n % p << '\n';

	return 0;
}