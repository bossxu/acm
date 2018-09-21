#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define c_fuck(x) cout<<"Case "<<x<<":"
#define debug cout<<"is there bug?"<<endl
const int mod = 1e9+7;
const double eps = 1e-6;
char s[200];
int check(char a)
{
  if (a>='a' && a<='z') return 0;
  if(a>='0' && a<='9') return 1;
  if(a>='A' && a<='Z') return 2;
}
int shu[4];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>s;clr(shu,0);
    for(int i = 0;i<strlen(s);i++)
    {
        shu[check(s[i])]++;
    }
    int ans = 0;
    for(int i = 0 ;i< 3;i++) if(shu[i] == 0) ans++;
    //cout<<ans<<endl;
    if(ans == 2)
    {
      int ko = -1;
      for(int i = 0;i<3;i++) if(shu[i]>0) ko = i;
      if(ko == 0) s[0] = '1',s[1] = 'A';
      if(ko == 1) s[0] = 'a',s[1] = 'A';
      if(ko == 2) s[0] = 'a',s[1] = '1';
    }
    if(ans == 1)
    {
      int tit = -1,mu = -1;
      for(int i = 0;i<3;i++)
      {
        if(shu[i] > 1) mu = i;
        if(shu[i] == 0) tit = i;
      }
      for(int i = 0;i<strlen(s);i++)
      {
        if(check(s[i]) == mu)
        {
          if(tit == 0) s[i] = 'a';
          if(tit == 1) s[i] = '1';
          if(tit == 2) s[i] = 'A';
          break;
        }
      }
    }
    cout << s<<endl;
  }
  return 0;
}
