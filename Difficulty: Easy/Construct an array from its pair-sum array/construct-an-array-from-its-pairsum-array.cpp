#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& arr) {
        int m = arr.size();
        if (m == 0) return {};
        if (m == 1) return {1, arr[0] - 1};
        long long n = (1 + (long long)floor(sqrt(1 + 8.0L * m))) / 2;
        while (n * (n - 1) / 2 < m) ++n;
        while (n * (n - 1) / 2 > m) --n;
        vector<int> res(n);
        long long a = arr[0];
        long long b = arr[1];
        long long c = arr[n - 1];
        long long r0 = (a + b - c) / 2;
        res[0] = (int)r0;
        for (int i = 1; i < n; ++i) res[i] = (int)(arr[i - 1] - r0);
        return res;
    }
};
