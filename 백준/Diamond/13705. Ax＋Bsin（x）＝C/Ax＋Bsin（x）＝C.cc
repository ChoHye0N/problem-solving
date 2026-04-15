#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using qudf = __float128;
using qudi = __int128;

const qudf PI = 3.14159265358979323846264338327950288419Q;
const qudf MOD = 1000000;

qudf taylor_series(qudf x) 
{
    x = x - (qudi)(x / (PI * 2)) * PI * 2;

    qudf result = x, term = x, currentTerm = x;

    for (qudf step = 0; step <= 100; step++)
    {
        qudf deno = 2 * step + 3;
        currentTerm *= (-1) * x * x / ((deno - 1) * deno);
        result += currentTerm;
    }

    return result;
}

qudf find_ans(qudf a, qudf b, qudf c) {
    qudf start = (c - b) / a, end = (c + b) / a;

    for (int i = 0; i < 1000; i++) {
        qudf mid = (start + end) / 2;
        qudf result = a * mid + b * taylor_series(mid) - c;

        if (result > -1e-70 && result < 1e-70) {
            return mid;
        }

        if (result > 0) {
            end = mid;
        }
        else {
            start = mid;
        }
    }
    return start;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    printf("%lf\n", (double)(qudi(MOD * find_ans(a, b, c) + (qudf)0.5) / MOD));

    return 0;
}