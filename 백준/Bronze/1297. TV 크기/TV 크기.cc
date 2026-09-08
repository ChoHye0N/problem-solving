#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double d, h, w;
	cin >> d >> h >> w;

	double ratio = d / sqrt(h * h + w * w);

	int height = (int)(h * ratio);
	int width = (int)(w * ratio);

	cout << height << ' ' << width;

	return 0;
}
