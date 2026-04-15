#include <iostream>
#include <algorithm>
#include <initializer_list>

using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
    cout << min({ w - x, h - y , x, y}) << '\n';

    return 0;
}