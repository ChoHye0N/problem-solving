#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a, b, c, s, v, l;
    cin >> a >> b >> c >> s >> v >> l;

    int need = (250 - l) * 100, t = 0, e1 = v * c * 30, e2 = s * b * 30;

    if (need > e1) need -= e1, t += v * 30;
    else return cout << (t + (need + c - 1) / c), 0;

    if (need > e2) need -= e2, t += s * 30;
    else return cout << (t + (need + b - 1) / b), 0;

    cout << t + (need + a - 1) / a;
}