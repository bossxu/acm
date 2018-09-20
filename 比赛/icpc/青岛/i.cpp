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
char s[100005];
int main()
{
  int t;scanf("%d",&t);
  while(t--)
  {
    scanf("%s",s);
    int k = strlen(s);
    char pre = s[0];
    ll ans = 1LL*k*(k+1)/2;
    if(s[0] == '0') ans+=k;
    for(int i = 1;i<k;i++)
    {
      ans+=1LL*(k-i)*(k+1-i)/2;
      if(s[i] == '1')
      {
        if(s[i-1] == '1')
        {
          ans += 1LL*i*(k-i);
        }
      }
      if(s[i] == '0')
      {
        ans += 1LL*(k-i);
        if(s[i-1] == '0')
        {
            ans += 1LL*i*(k-i);
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
