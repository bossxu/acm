#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int dp[2][1 << 20];

int main()
{
    int n, m;
    while(cin >> n >> m){
    vector<bitset<N> > vec(n);
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '1') vec[i].set(j);
    }
    if (m <= 20)
    {
        memset(dp, 0xc0, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            memset(dp[i & 1 ^ 1], 0xc0, sizeof(dp[i & 1 ^ 1]));
            for (int j = 0; j < (1 << m); j++)
                dp[i & 1 ^ 1][j] = max(dp[i & 1][j ^ (vec[i].to_ulong())] + 1, dp[i & 1][j]);
        }
        cout << dp[n & 1][0] << endl;
    }
    else
    {
        unordered_map<bitset<N>, int> dic;
        int nn = n / 2;
        int mm = n - nn;
        bitset<N> tmp;
        for (int i = 0; i < (1 << nn); i++)
        {
            tmp.reset();
            for (int j = 0; j < nn; j++)
                if (i >> j & 1)
                    tmp ^= vec[j];
            dic[tmp] = max(dic[tmp], __builtin_popcount(i));
        }
        int ans = 0;
        for (int i = 0; i < (1 << mm); i++)
        {
            tmp.reset();
            for (int j = 0; j < mm; j++)
                if (i >> j & 1)
                    tmp ^= vec[nn + j];
            ans = max(ans, dic[tmp] + __builtin_popcount(i));
        }
        cout << ans << endl;
    }
  }
    return 0;
}
