#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<long long> numbers(n);
    numbers[0] = x;

    for(int i = 1; i < n; i++)
    {
        long long generated = ((a * numbers[i - 1]) + b) % c;

        numbers[i] = generated;
    }

    long long tempResult = 0;
    for(int i = 0; i < k; i++)
    {
        tempResult += numbers[i];
    }

    long long result = tempResult;

    for(int i = 1; i <= n - k; i++)
    {
        tempResult = tempResult - numbers[i - 1] + numbers[i + k - 1];
        result ^= tempResult;
    }

    cout << result;

    return 0;
}
