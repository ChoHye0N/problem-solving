#include <iostream>
#include <string>

using namespace std;

string room_num(int num) {
    return num < 10 ? "0" + to_string(num) : to_string(num);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int h, w, n;
        cin >> h >> w >> n;

        int floor = (n % h == 0) ? h : n % h;
        int room = (n % h == 0) ? n / h : n / h + 1;

        cout << floor << room_num(room) << '\n';
    }

    return 0;
}