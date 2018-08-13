#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
int cha[4200][120];
int shu[4200][4200];
int num[4200];
int val[20];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //freopen("in.txt","r",stdin);
  int n,m,q;
  while(cin>>n>>m>>q)
  {
    clr(num,0);
    clr(shu,0);
    clr(cha,0);
    for(int i = 0;i<n;i++)
    {
      cin>>val[i];
    }
    for(int i = 1;i<=m;i++)
    {
      string s;
      cin>>s;
      //cout<<s<<endl;
      int ans = 0;
      for(int i = 0;i<n;i++)
      {
        ans = ans*2+s[i]-'0';
      }
      //cout<<ans<<endl;
      num[ans]++;
    }
    for(int i = 0;i<(1<<n);i++)
    {
      for(int j = 0;j<(1<<n);j++)
      {
        if(num[j]==0) continue;
        int a = i,b = j;
        int op = 0;
        for(int k = n-1;k>=0;k--)
        {
          if(a%2 == b%2) op += val[k];
          a>>=1;b>>=1;
        }
        shu[i][j] = min(op,101);
      }
    }
    //cout<<"hello"<<endl;
    for(int i = 0;i<(1<<n);i++)
    {
      for(int j = 0;j<(1<<n);j++)
      {
        cha[i][shu[i][j]]+=num[j];
      }
      for(int j = 1;j<=100;j++)
      {
        cha[i][j] += cha[i][j-1];
      }
    }
    for(int i = 1;i<=q;i++)
    {
      string s;
      int k;
      cin>>s>>k;
      int ans = 0;
      for(int i = 0;i<n;i++)
      {
        ans = ans*2+s[i]-'0';
      }
      cout<<cha[ans][k]<<endl;
    }
  }
  return 0;
}
