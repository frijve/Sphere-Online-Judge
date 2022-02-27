// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ll a, b, c, d, m, n, i, j, k, l, x, y, z, t, count;

    vector<int> ans;

    int value[5];
    ll total, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum = 0;
    cin >> t;

    while (t > 0)
    {
        cin >> n >> m >> a >> d;
        t--;
        value[0] = a;
        value[1] = a + d;
        value[2] = a + (2 * d);
        value[3] = a + (3 * d);
        value[4] = a + (4 * d);

        for (i = 0; i < 5; i++)
        {
            sum1 += ((m / value[i]) - (n / value[i]));
            if ((n % value[i]) == 0)
                sum1++;
        }

        for (i = 0; i < 5; i++)
        {
            for (j = i + 1; j < 5; j++)
            {
                count = lcm(value[i], value[j]);
                sum2 += ((m / count) - (n / count));
                if ((n % count) == 0)
                    sum2++;
            }
        }
        for (i = 0; i < 5; i++)
        {
            for (j = i + 1; j < 5; j++)
            {
                for (k = j + 1; k < 5; k++)
                {
                    count = lcm(value[i], lcm(value[j], value[k]));
                    sum3 += ((m / count) - (n / count));
                    if ((n % count) == 0)
                        sum3++;
                }
            }
        }

        for (i = 0; i < 5; i++)
        {
            for (j = i + 1; j < 5; j++)
            {
                for (k = j + 1; k < 5; k++)
                {
                    for (l = k + 1; l < 5; l++)
                    {
                        count = lcm(value[i], lcm(value[j], lcm(value[k], value[l])));
                        sum4 += ((m / count) - (n / count));
                        if ((n % count) == 0)
                            sum4++;
                    }
                }
            }
        }

        count = lcm(value[0], lcm(value[1], lcm(value[2], lcm(value[3], value[4]))));
        sum5 += ((m / count) - (n / count));
        if ((n % count) == 0)
            sum5++;

        sum = ((m - n) + 1) - (sum1 - sum2 + sum3 - sum4 + sum5);
        ans.push_back(sum);

        // cout << sum << endl;
        sum1 = 0;
        sum2 = 0;
        sum3 = 0;
        sum4 = 0;
        sum5 = 0;
        sum = 0;
    }
    for (auto &p : ans)
    {
        cout << p << endl;
    }
}