#include <iostream>
using namespace std;

int main() 
{
    int a[6], b[6];
    
    for (int i = 0; i < 6; i++){
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++){
        cin >> b[i];
    }
    
    double w = 0, l = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (a[i] > b[j]) w++;
            else if (a[i] < b[j]) l++;
        }
    }
    
    printf("%.5f", w / (w + l));
    
    return 0;
}