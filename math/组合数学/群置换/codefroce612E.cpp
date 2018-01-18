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
// 如何 快速求出 置换群的多少次方
// 首先要化成那个 循环的模式,再进行操作
// 这波真的是骚操作
// 这题针对的是
vector< vector<int> >Q[1000005];
int shu[1000005];
int vis[1000005];
int n;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>n)
  {
    //cout<<n<<endl;
    for(int i = 1;i<=n;i++)
    {
      scanf("%d",&shu[i]);
    }
    clr(vis,0);
    for(int i = 1;i<=n;i++)
    {
      if(!vis[i])
      {
        vector<int>q;
        int st = i;
        while(!vis[st])
        {
          //cout<<st<<"-->"<<shu[st]<<endl;
          q.push_back(st);
          vis[st] = 1;
          st = shu[st];
        }
        Q[q.size()].push_back(q);
      }
    }
    for(int i = 1;i<=n;i++)
    {
      if(i%2 == 1)//为奇数的情况
      {
        int jump = (i+1)/2;
        for(int j = 0;j<Q[i].size();j++)
        {
          for(int k = 0;k<i;k++)
          {
            shu[Q[i][j][k]] = Q[i][j][(k+jump)%i];
            //cout<<shu[Q[i][j][k]]<<"<--"<< Q[i][j][(k+jump)%i]<<endl;
          }
        }
      }
      else
      {
        if(Q[i].size()%2)
        {
          cout<<"-1"<<endl;
          return 0;
        }
        else
        {
          for(int j = 0;j<Q[i].size();j+=2)
          {
            for(int l = 0;l<i;l++)
            {
              shu[Q[i][j][l]] = Q[i][j+1][l];
              //cout<<shu[Q[i][j][l]]<< "<--"<<Q[i][j+1][l]<<endl;
              shu[Q[i][j+1][l]] = Q[i][j][(l+1)%i];
              //cout<<shu[Q[i][j+1][l]]<<"<--"<<Q[i][j][(l+1)%i]<<endl;
            }
           }
         }
    }
  }
   for(int i =1;i<=n;i++)
   printf("%d ",shu[i]);
   cout<<endl;

}
  return 0;
}
