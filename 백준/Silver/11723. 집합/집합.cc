#include <iostream>
#include <vector>
#include <string>

using namespace std;

int set(vector<int>& list, const string& command, int num) {
    int index = num - 1;
    if (command == "add") list[index] = 1;
    else if (command == "remove") list[index] = 0;
    else if (command == "check") return list[index] ? 1 : 0;
    else if (command == "toggle") list[index] = list[index] ? 0 : 1;
    else if (command == "all") list = vector<int>(20, 1);
    else if (command == "empty") list = vector<int>(20, 0);

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> set_list(20, 0);
    int size, num = -1;

    cin >> size;
    cin.ignore();

    for (int i = 0; i < size; i++) {
        string command;
        cin >> command;

        if (command == "add" || command == "remove" || command == "check" || command == "toggle")
            cin >> num;

        int return_set = set(set_list, command, num);

        if (return_set != -1) cout << return_set << "\n";
    }

    return 0;
}