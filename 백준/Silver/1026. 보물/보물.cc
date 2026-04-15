#include <bits/stdc++.h>

using namespace std;

bool compare(int x, int y){
  return x > y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  vector<int> aArr(n);
  vector<int> bArr(n);
  
  for(int i=0; i<n; i++){
    cin >> aArr[i];
  }
  for(int i=0; i<n; i++){
    cin >> bArr[i];
  }
  
  sort(aArr.begin(), aArr.end());
  sort(bArr.begin(), bArr.end(), compare);
  
  int sum = 0;
  for(int i=0; i<n; i++){
    sum += aArr[i] * bArr[i];
  }
  
  cout << sum << '\n';
  
  return 0;
}