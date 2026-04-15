#include <iostream>
#include <vector>
#include <algorithm>

#define STR_SIZE 10

using namespace std;

int main() {
	vector<int> arr;

	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp % 42);
	}
    
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	cout << arr.size() << '\n';

	return 0;
}