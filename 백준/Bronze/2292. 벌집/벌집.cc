#include <iostream>

using namespace std;

int main() {
	int n, total = 1, lineSize = 1;
	cin >> n;

	for (lineSize = 1; total < n; lineSize++) total += 6 * lineSize;

	cout << lineSize << '\n';
}