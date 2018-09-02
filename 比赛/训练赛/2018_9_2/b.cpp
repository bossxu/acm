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
char s[1000005];
bool check(int st1,int st2,int len)
{
  for(int i = 1;i<len;i++)
  {
    if(s[i+st1] == s[i+st2]) continue;
    return s[i+st1] > s[i+st2];
  }
  return 0;
}
int main()
{
  int n ;
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
    while(scanf("%d",&n)==1)
{    scanf("%s",s);
    int item = 0;
    for(int i = 1;i<n;i++)
    {
      if(s[i] < s[0]) item = 1;
    }
    for(int i = n;i<2*n;i++)
    {
      s[i] = s[i-n];
    }
    if(!item)
    {
      int op = 0;
      int last = 1;
      for(int i = 1;i<n && !op;i++)
      {
        if(s[i] > s[0]) last = 1;
        if(last && s[i] == s[0])
        {
          if(check(0,i,n))
          {
            op = 1;
          }
          last = 0;
        }
      }
      if(op) cout<<"No"<<endl;
      else
      cout<<"Yes"<<endl;
    }
    else
    {
      cout<<"No"<<endl;
    }
  }
  return 0;
}
