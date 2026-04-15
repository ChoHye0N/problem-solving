#include <iostream>
#include <map>
#include <cctype>
#include <string>

using namespace std;

bool isInteger(const string& str) {
	if (str.empty()) return false;

	for (char ch : str) {
		if (!std::isdigit(ch)) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;

	cin >> n >> m;

	map<int, string> pokemon_number_dict;
	map<string, int> pokemon_name_dict;

	for (int no = 1; no < n + 1; no++) {
		string pokemon;
		cin >> pokemon;
		pokemon_number_dict[no] = pokemon;
		pokemon_name_dict[pokemon] = no;
	}

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;

		if (isInteger(temp))
			cout << pokemon_number_dict[stoi(temp)] << '\n';
		else
			cout << pokemon_name_dict[temp] << '\n';
	}

	return 0;
}