#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    vector<string> arr(5 * n);
    for (int i = 0; i < n; i++){
      string str = "";
      
      for (int j = 0; j < 5; j++){
          string temp;
          cin >> temp;
          str += temp;
      }
      arr[i] = str;
    }
    
    int minDiff = 36;
    vector<int> ans(2, 0);
    for (int i = 0; i < n; i++){
      for (int j = i + 1; j < n; j++){
          int diff = 0;
          
          for (int k = 0; k < arr[i].size(); k++){
              if (arr[i][k] != arr[j][k]) diff++;
          }
          
          if (minDiff > diff){
              minDiff = diff;
              ans = { i + 1, j + 1 };
          }
      }
    }
    
    cout << ans[0] << ' ' << ans[1];
    
    return 0;
}