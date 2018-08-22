#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
const int N = 20000000;
ll dp[N+5];
ll phi[N+6];
ll prime[N+6];
bool unprime[N+6];
void init()
{
	int i, j, k = 0;
	for (i = 2; i < N; i++)
	{
		if (!unprime[i])
		{
			prime[k++] = i;
			phi[i] = i - 1;
		}
		for (j = 0; j < k && prime[j] * i < N; j++)
		{
			unprime[prime[j] * i] = true;
			if (i % prime[j])
				phi[prime[j] * i] = phi[i] * (prime[j] - 1);
			else
			{
				phi[prime[j] * i] = phi[i] * prime[j];
                break;
			}
		}
	}

  for(int i = 1;i<=N;i+=2)
  {
    phi[i]/=2;
  }
  dp[0] = 0;
  for(int i = 1;i<=N;i++)
  {
    dp[i] = dp[i-1] + phi[i];
  }
}
int main()
{
  int t;
  scanf("%d",&t);
  init();
  while(t--)
  {
    int n;
    scanf("%d",&n);
    cout<<dp[n]<<endl;
  }
  return 0;
}
