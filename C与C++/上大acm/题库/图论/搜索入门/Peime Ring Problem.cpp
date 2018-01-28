#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int prime[40],vis[40],a[40];
int N;
void dfs(int deep)
{
    int i;
    if(deep==N && prime[a[deep-1]+a[0]])
    {
          for(i=0;i<deep-1;i++) 
          printf("%d ",a[i]);
          printf("%d\n",a[deep-1]);

    }
    else
    {
        for(i=2;i<=N;i++)
        {
            if(vis[i]) continue;
            else
            {
                if(prime[i+a[deep-1]])
                {
                    vis[i]=1;
                    a[deep++]=i;
                    dfs(deep);
                    vis[i]=0;//  个人感觉这是灵魂之处 这样我就能用栈存下来
                    // 这样我也能用一个栈来存，并且打印路径。
                    deep--;
                }
            }
        }
    }
}

int main()
{
    int cnt=0;
    memset(prime,0,sizeof(prime));
    prime[2]=1;prime[3]=1;prime[5]=1;prime[7]=1;prime[11]=1;
    prime[13]=prime[17]=prime[19]=prime[23]=prime[29]=prime[31]=1;
    prime[37]=1;
  while(cin>>N)
  {
    printf("Case %d:\n",++cnt);
    memset(vis,0,sizeof(vis));
    a[0]=1;
    dfs(1);
    printf("\n");
  }
}