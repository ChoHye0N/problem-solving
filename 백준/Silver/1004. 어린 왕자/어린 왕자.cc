#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

struct Planet{
    int x, y, r;
};

int res;

void check_area(Planet pt, Point s, Point e){
    int rs = (pt.x - s.x) * (pt.x - s.x) + (pt.y - s.y) * (pt.y - s.y);
    int re = (pt.x - e.x) * (pt.x - e.x) + (pt.y - e.y) * (pt.y - e.y);

    if ((rs <= pt.r * pt.r) ^ (re <= pt.r * pt.r)) res++;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--){
        Point s, e;
        cin >> s.x >> s.y >> e.x >> e.y;

        int n;
        cin >> n;

        res = 0;
        for (int i = 0; i < n; i++){
            int x, y, r;
            cin >> x >> y >> r;

            check_area({x, y, r}, s, e);
        }

        cout << res << '\n';
    }

    return 0;
}