// CodeForce 7C. Line
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long extgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long d = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    long long abs_a = a;
    if (abs_a < 0)
    {
        abs_a = -abs_a;
    }

    long long abs_b = b;
    if (abs_b < 0)
    {
        abs_b = -abs_b;
    }

    long long x0, y0;
    long long g = extgcd(abs_a, abs_b, x0, y0);

    if (c % g != 0)
    {
        cout << -1 << "\n";
    }
    else
    {
        long long mult = -c / g;
        long long x = x0 * mult;
        long long y = y0 * mult;

        if (a < 0)
        {
            x = -x;
        }

        if (b < 0)
        {
            y = -y;
        }

        cout << x << " " << y << "\n";
    }

    return 0;
}
#endif