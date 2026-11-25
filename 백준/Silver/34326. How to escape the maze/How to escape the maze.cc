#include <bits/stdc++.h>
using namespace std;

int n, m;
int sx, sy, ex, ey;
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
vector<string> arr;

int left(int pos){
    int x = sx, y = sy, cnt = 0;

    while (x != ex || y != ey){
        pos--;
        if (pos < 0) pos = 4 + pos;
        
        while (true){
            int nx = x + dx[pos % 4], ny = y + dy[pos % 4];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                if (arr[ny][nx] == '.' || arr[ny][nx] == 'E') break;
            };

            pos++;
        }

        x += dx[pos % 4], y += dy[pos % 4];
        cnt++;
    }

    return cnt;
}

int right(int pos){
    int x = sx, y = sy, cnt = 0;

    while (x != ex || y != ey){
        pos++;
        
        while (true){
            int nx = x + dx[pos % 4], ny = y + dy[pos % 4];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                if (arr[ny][nx] == '.' || arr[ny][nx] == 'E') break;
            };

            pos--;
            if (pos < 0) pos = 4 + pos;
        }
        
        x += dx[pos % 4], y += dy[pos % 4];
        cnt++;
    }

    return cnt;
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int pos = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == 'S'){
                sx = j, sy = i;
                for (int k = 0; k < 4; k++){
                    int nx = j + dx[k], ny = i + dy[k];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (arr[i + dy[k]][j + dx[k]] == '.') pos = k;
                }
            }
            if (arr[i][j] == 'E') ex = j, ey = i;
        }
    }

    string ans;
    int l = left(pos), r = right(pos);

    if (l > r) ans = "RIGHT IS BEST";
    else if (l == r) ans = "SAME";
    else ans = "LEFT IS BEST";

    cout << ans;

    return 0;
}