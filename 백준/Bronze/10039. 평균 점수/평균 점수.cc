#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    
    for(int i=0; i<5; i++){
        int num;
        cin >> num;    

        if(num < 40) num = 40;
        ans += num;
    }
    cout << ans / 5 << '\n';
    
    return 0;
}