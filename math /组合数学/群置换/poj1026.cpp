#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#define clear(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

// 讲道理,感觉这题比较水,就跳了,就是模拟,没啥意思
using namespace std;

struct node1
{
    int num,jie;
} node[205];
char s[205];
bool vis[205];
int main()
{
    int n,cnt,p,k;
    while(scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&node[i].num);
        }
        clearall(vis,false);
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                p=node[i].num;
                cnt=1;
                vis[i]=true;
                while(p!=i)
                {
                    cnt++;
                    p=node[p].num;
                    vis[p]=true;
                }
                node[i].jie=cnt;
                p=node[i].num;
                while(p!=i)
                {
                    node[p].jie=cnt;
                    p=node[p].num;
                }
            }
        }
        while(scanf("%d",&k),k)
        {
            gets(s);
            int len=strlen(s);
            for(int i=len; i<=n; i++)
            {
                s[i]=' ';
            }
            s[n+1]='\0';
            clearall(vis,false);
            char c,t;
            for(int i=1; i<=n&&k; i++)
            {
                if(!vis[i])
                {
                    for(int j=0; j<k%node[i].jie; j++)
                    {
                        p=i;
                        c=s[node[p].num];
                        s[node[p].num]=s[i];
                        p=node[p].num;
                        vis[i]=true;
                        while(p!=i)
                        {
                            vis[p]=true;
                            t=s[node[p].num];
                            s[node[p].num]=c;
                            c=t;
                            p=node[p].num;
                        }
                    }
                }
            }
            puts(s+1);
        }
        puts("");
    }
    return 0;
}
