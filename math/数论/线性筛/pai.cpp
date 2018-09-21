#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

const int MAX = 1e5 + 5;
bool u[MAX];
int prime[MAX], num;

void initial()
{
    memset(u, true, sizeof(u));
    num = 0;
    for(int i = 2; i < MAX; i++)
    {
        if(u[i])
            prime[num++] = i;
        for(int j = 0; j < num; j++)
        {
            if(i*prime[j] >= MAX)
                break;
            u[i*prime[j]] = false;
            if(i%prime[j] == 0)
                break;
        }
    }
}

int n;

void input()
{
    scanf("%d", &n);
}

void solve()
{
    long long ans = 1, other = n;
    for(int i = 0; prime[i]*prime[i] <= n; i++)
    {
        if(n%prime[i] == 0)
        {
            int cnt = 1;
            long long mul = 1;
            while(n%prime[i] == 0)
            {
                mul *= prime[i];
                cnt++;
                n /= prime[i];
            }
            other *= cnt;
            mul *= prime[i];
            long long a = (mul - 1)/(prime[i] - 1), b = mul + 1, c = prime[i] + 1;
            ans *= ((a/c)*(b/c)*c + a%c*(b/c) + b%c*(a/c)); //防溢出计算(mul^2 - 1)/(prime[i]^2 - 1)
        }
    }
    if(n > 1)
    {
        other *= 2;
        ans *= (1 + (long long)n*n);
    }
    printf("%lld\n", ans - other);
}

int main()
{
    initial();
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        input();
        solve();
    }
    return 0;
}
