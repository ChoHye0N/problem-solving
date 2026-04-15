#include <iostream>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int count = 0;
    
    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            if ((n / d + d) % 2 == 0 && (n / d - d) % 2 == 0) {
                int a = (n / d + d) / 2, b = (n / d - d) / 2;

                if (b >= 1 && b <= a) count++;
            }
        }
    }

    cout << count << '\n';
    
    return 0;
}
