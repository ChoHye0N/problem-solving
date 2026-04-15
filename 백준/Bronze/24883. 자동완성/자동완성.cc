#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> c;
    
    (c == 'N' || c == 'n') ? cout << "Naver D2\n" : cout << "Naver Whale\n";

    return 0;
}