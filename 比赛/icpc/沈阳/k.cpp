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
char num[1004];
int vis[] = {2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,173,311,317};
int main()
{
  ios_close;
  int t;
  cin>>t;
  int tot = 0;
  while(t--)
  {
    cin>>num;
    cout<<"Case #"<<(++tot)<<": ";
    if(strlen(num)<=4)
    {
      ll ans = 0;
      for(int i = 0;i<strlen(num);i++)
      {
        ans = ans*10+num[i]-'0';
      }
      int ko = 317;
      for(int i = 0;i<19;i++)
      {
        if(ans >= vis[i])
        {
          ko = vis[i];
        }
        else
        break;
      }
      cout<<ko<<endl;
    }
    else
    {
      cout<<317<<endl;
    }
  }
  return 0;
}
