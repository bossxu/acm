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
const double eps = 1e-6;
vector<int>map[10005];
int in[10005];
int w[10005];
int len,num;
void init(int n)
{
   len=num=0;
   for(int i=1;i<=n;i++)
   {
       map[i].clear();
   }
    clr(in,0);
    clr(w,0);
}
void topsort(int n)///vector版本的拓扑排序模板
{
    int j;
    priority_queue<int,vector<int>,greater<int> >qq;///最小堆优队
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
            qq.push(i);
    }
    while(!qq.empty())
    {
        j=qq.top();
        qq.pop();
        num++;
        for(int i=0;i<map[j].size();i++)
        {
            int k=map[j][i];
            in[k]--;
            if(w[j]+1>w[k])
                w[k]=w[j]+1;///求最少的钱，又后边的奖金比前面大，故贪心的加1就是最少的
            if(in[k]==0)
                qq.push(k);
        }
    }
}
int main()
{
    int n,m;
    
    while(scanf("%d%d",&n,&m)==2)
    {
        init(n);
        int it = 0;
      while(m--)
      {
          int i,j;
          cin>>i>>j;
          map[j].push_back(i);
          in[i]++;
      }
        topsort(n);
     int sum = n*888;
     for(int i=1;i<=n;i++)
     {
        sum+=w[i];
     }
     if(num>=n)
     printf("%d\n",sum);
     else
     printf("-1\n");

     }
    return 0;
}