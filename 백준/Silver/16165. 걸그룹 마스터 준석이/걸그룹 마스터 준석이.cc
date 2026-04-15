#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<string, vector<string>> girlGroups;

    for (int i = 0; i < n; i++) {
        string groupName;
        vector<string> girlGroup;
        int num;
        cin >> groupName >> num;

        for (int j = 0; j < num; j++) {
            string temp;
            cin >> temp;

            girlGroup.push_back(temp);
        }
        sort(girlGroup.begin(), girlGroup.end());
        girlGroups[groupName] = girlGroup;
    }

    for (int i = 0; i < m; i++) {
        string name;
        int op;
        cin >> name >> op;

        if (op == 0)
            for(string group : girlGroups[name])
                cout << group << '\n';

        else
            for (const auto& group : girlGroups)
                for(string girl : group.second)
                    if (girl == name)
                        cout << group.first << '\n';
    }

    return 0;
}