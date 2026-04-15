#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int dist(const Point& p1, const Point& p2) {
    int dx = p1.x - p2.x, dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}

int closest_recursive(vector<Point>& Sx, vector<Point>& Sy) {
    int n = Sx.size();
    
    if (n <= 3) {
        int minDist = dist(Sx[0], Sx[1]);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                minDist = min(minDist, dist(Sx[i], Sx[j]));
            }
        }
        return minDist;
    }
    
    int mid = n / 2, midX = Sx[mid].x;
    
    vector<Point> Sy_L, Sy_R;
    Sy_L.reserve(mid);
    Sy_R.reserve(n - mid);
    
    for (const Point& p : Sy) {
        if (p.x <= midX) Sy_L.push_back(p);
        else Sy_R.push_back(p);
    }
    
    vector<Point> Sx_L(Sx.begin(), Sx.begin() + mid),
        Sx_R(Sx.begin() + mid, Sx.end());
    
    int d = min(closest_recursive(Sx_L, Sy_L), closest_recursive(Sx_R, Sy_R));
    
    vector<Point> strip;
    strip.reserve(n);
    
    for (const Point& p : Sy) {
        if (abs(p.x - midX) < d) {
            strip.push_back(p);
        }
    }
    
    int sz = strip.size();
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    
    return d;
}

int closest_pair(vector<Point>& points) {
    vector<Point> Sy = points;
    
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    sort(Sy.begin(), Sy.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });
    
    return closest_recursive(points, Sy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    cout << closest_pair(points);
    
    return 0;
}