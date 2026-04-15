#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int isReverse = 0;

int ac(const vector<char>& commandList, vector<int>& numList) {
	isReverse = 0;
	
	for (char command : commandList) {
		if (command == 'R') isReverse = 1 - isReverse;
		else {
			if (numList.empty()) return -1;

			if (isReverse == 0) numList.erase(numList.begin());
			else if (isReverse == 1) numList.pop_back();
		}		
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	cin.ignore();

	for (int i = 0; i < t; i++) {
		vector<char> commandList;
		vector<int> numList;

		string inputCommand;
		string inputNum;
		string temp;

		// Get command
		getline(cin, inputCommand);
		for (char c : inputCommand)
			commandList.push_back(c);

		// Get number size
		int numListSize;
		cin >> numListSize;
		cin.ignore();

		// Get number list
		getline(cin, inputNum);
		inputNum.erase(0, 1);
		inputNum.pop_back();
		istringstream ss(inputNum);
		while (getline(ss, temp, ','))
			numList.push_back(stoi(temp));
		
		// Processing ac 
		int answer = ac(commandList, numList);
		if (answer == 0) {
			cout << '[';
			if (!numList.empty()) {
				if (isReverse == 0) {
					for (int i = 0; i < numList.size() - 1; i++) {
						cout << numList[i] << ',';
					}
					cout << numList[numList.size() - 1];
				}
				else {
					for (int i = numList.size() - 1; i >= 1; i--) {
						cout << numList[i] << ',';
					}
					cout << numList[0];
				}
			}
			cout << ']' << '\n';
		}

		else if (answer == -1)
			cout << "error" << '\n';
	}

	return 0;
}