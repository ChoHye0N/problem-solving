#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        vector<string> students;
        string student;
        while (ss >> student) {
            students.push_back(student);
        }

        string chooser;
        cin >> chooser;

        int n;
        cin >> n;
        cin.ignore();

        int start = 0;
        for (int j = 0; j < students.size(); j++) {
            if (students[j] == chooser) {
                start = j;
                break;
            }
        }

        cout << students[(start + (n - 1)) % students.size()] << '\n';
    }

    return 0;
}