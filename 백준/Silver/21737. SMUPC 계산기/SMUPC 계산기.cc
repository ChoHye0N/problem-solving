#include <bits/stdc++.h>
using namespace std;

int i = 0;

int ps(string &str){
    string res = "";
    bool flag = false;
    
    for (; i < str.size(); i++){
        if (str[i] < '0' || str[i] > '9') break;
        if (str[i] != '0' || flag){
            res += str[i];
            flag = true;
        }
    }
    
    return (res.size() ? stoi(res) : 0);
}

int main() 
{
    int n;
    string str;
    cin >> n >> str;
    
    bool flag = false;
    int sn = ps(str), curr;
    
    while (n--){
        if (str[i] == 'S'){
            i++;
            sn -= ps(str);
        }
        else if (str[i] == 'M'){
            i++;
            sn *= ps(str);
        }
        else if (str[i] == 'U'){
            i++;
            int tmp = ps(str);
            if (tmp == 0) break;
            sn /= tmp;
        }
        else if (str[i] == 'P'){
            i++;
            sn += ps(str);
        }
        else if (str[i] == 'C'){
            cout << sn << ' ';
            flag = true;
            i++;
        }
    }
    
    if (!flag) cout << "NO OUTPUT";
    
    return 0;
}