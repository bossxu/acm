#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<set>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s[105][105];
int map[27][27];

int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  //std::ios::sync_with_stdio(false);
  int n;
  while(cin>>n)
  {
    clr(map,0);
    for(int i = 0;i<n;i++)
    {
      cin>>s[i];
    }
    int item = 0;
    for(int i = 0;i<n;i++)
    {
      for(int j = i+1;j<n;j++)
      {
        int len1 = strlen(s[i]);
        int len2 = strlen(s[j]);
        int k;
        int flag = 0;
        for(k = 0;k<min(len1,len2);k++)
        {
          if(s[i][k]!=s[j][k])
          {flag = 1;break;}
        }
        if(flag == 0)
        {
          if(len1>len2)
          {
            item = 1;
          }
        }
        if(flag)
        {
          map[s[i][k]-'a'][s[j][k]-'a'] = 1;
        }
      }
    }
    if(item)
    {
      cout<<"Impossible"<<endl;
      continue;
    }
    int vis[27];
    clr(vis,0);
    vector<int>l;
    for(int k = 0;k<26;k++)
    {
      for(int i = 0;i<26;i++)
      {
        if(vis[i]) continue;
        int flag = 1;
        for(int j = 0;j<26;j++)
        {
          if(map[j][i] && !vis[j])
          {
            flag = 0;
          }
        }
        if(flag)
        {
          l.push_back(i);
          vis[i] = 1;
          break;
        }
      }
    }
    if(l.size()!=26)
    {
      cout<<"Impossible"<<endl;
      continue;
    }
    for(int i = 0;i<26;i++)
    {
      printf("%c",l[i]+'a');
    }
    cout<<endl;

  }
  return 0;
}
