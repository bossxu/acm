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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int shu[2][20];
int ans[20];
int vis[20];
int init(ll a,int x)
{
   int i = 0;
   int p[20];
   while(a!=0)
   {
     p[i++] = a%10;
     a/=10;
   }
   int k = 0;
   for(int j = i-1;j>=0;j--)
   {
     shu[x][k++] = p[j];
   }
   return i;
}
int dfs(int pos,int length,int flag)
{
  //cout<<pos<<endl;
  int minn = 0;
  int index;
   if(pos == length)
   {
     return 1;
   }
   int ok = 0;
   for(int i = 0;!ok && i<length;i++)
   {
     /*cout<<vis[i]<<"->"<<shu[0][i]<<" ->"<<flag<<endl;
     for(int j = 0;j<pos;j++)
     cout<<ans[j];
     cout<<endl;*/
      if(flag && !vis[i])
      {
        ans[pos] = shu[0][i];
        vis[i] = 1;
        ok = dfs(pos+1,length,flag);
        vis[i] = 0;
      }
      if(!flag && !vis[i] && shu[0][i]<=shu[1][pos])
      {
        if(shu[0][i] == shu[1][pos])
        {
          ans[pos] = shu[0][i];
          vis[i] = 1;
          ok = dfs(pos+1,length,0);
          vis[i] = 0;
        }
        else
        {
          ans[pos] = shu[0][i];
          vis[i] = 1;
          ok = dfs(pos+1,length,1);
          vis[i] = 0;
        }
      }
   }
   return ok;

}
int cmp(int a,int b)
{
  return a>b;
}
int main()
{
   ll a,b;
   while(cin>>a>>b)
   {
      int lena = init(a,0);
      int lenb = init(b,1);
      if(lena < lenb)
      {
        sort(shu[0],shu[0]+lena,cmp);
        for(int i = 0;i<lena;i++)
        {
          cout<<shu[0][i];
        }
        cout<<endl;
      }
      else
      {
         clr(vis,0);
         sort(shu[0],shu[0]+lena,cmp);
         //cout<<shu[0][0]<<endl;
         int l = dfs(0,min(lena,lenb),0);
         for(int i = 0;i<min(lena,lenb);i++)
         {
           cout<<ans[i];
         }
         cout<<endl;
      }

   }
  return 0;
}
