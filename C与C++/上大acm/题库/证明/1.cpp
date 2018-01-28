#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
#define INF 0x7f7f7f
#define maxn 1000005

int in[10010],x[10010],money[10010];
int len,num;
int n,m;
vector<int>E[10010];

void init()
{
    for(int i=1;i<=n;i++)
    {
        in[i]=0;
        E[i].clear();
        money[i]=888;
    }
    len=0;
    num=0;
}

void topsort()///vector版本的拓扑排序模板
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
        x[++len]=j;
        for(int i=0;i<E[j].size();i++)
        {
            int k=E[j][i];
            in[k]--;
            if(money[j]+1>money[k])
                money[k]=money[j]+1;///求最少的钱，又后边的奖金比前面大，故贪心的加1就是最少的
            if(in[k]==0)
                qq.push(k);
        }
    }
}

int main()
{
    int x,y;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            E[y].push_back(x);
            in[x]++;
        }
        topsort();
        if(num<n)
            printf("-1\n");
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                ans+=money[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}