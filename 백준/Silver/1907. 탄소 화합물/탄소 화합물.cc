#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string str;
    cin >> str;
    
    vector<map<char, int>> arr(3);
    vector<char> check = {'C', 'H', 'O'};
    int idx = 0;
    
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '+' || str[i] == '=') idx++;
        else if (str[i] >= 'A' && str[i] <= 'Z'){
            if (i < str.size() - 1 && str[i + 1] >= '2' && str[i + 1] <= '9'){
                arr[idx][str[i]] += str[i + 1] - '0';
                i++;
            }
            else arr[idx][str[i]]++;
        }
    }
    
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            for (int k = 1; k <= 10; k++){
                bool flag = true;
                
                for (int x = 0; x < 3; x++){
                    int l = i * arr[0][check[x]] + j * arr[1][check[x]], 
                        r = k * arr[2][check[x]];
                    
                    if (l != r) flag = false;
                }
                
                if (flag){
                    cout << i << ' ' << j << ' ' << k;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}