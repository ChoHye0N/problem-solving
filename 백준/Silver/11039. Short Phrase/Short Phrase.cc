#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string w[50];
    int check[5] = {5, 7, 5, 7, 7};
    
    while (1){
        int n;
        cin >> n;
        
        if (n == 0) break;
        
        for (int i = 0; i < n; i++){
            cin >> w[i];
        }
        
        int ans = 0;
        for (int s = 0; s < n; s++){
            int sum = 0, cycle = 0;
            
            for (int i = s; i < n; i++){
                sum += w[i].size();
                
                if (sum == check[cycle]){
                    sum = 0, cycle++;
                    
                    if (cycle == 5){
                        ans = s + 1;
                        break;
                    }
                } 
                else if (sum > check[cycle]) break;
            }
            if (ans) break;
        }
        cout << ans << '\n';
    }
    
    return 0;
}