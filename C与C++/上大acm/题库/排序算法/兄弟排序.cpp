#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct st{
    int xian;
    int pai;
}node[1000006];
int cmp(st a,st b)
{
    if(a.xian<b.xian) return 1;
    return 0;
}
int main()
{
    int t,ca=0;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&node[i].xian);
            node[i].pai=i;
        }
        sort(node+1,node+n+1,cmp);
        int sum = 0,jian = 0;
        for(int i=1;i<=n;i++)
        {
            int c = node[i].pai-i-jian;
            if(c>0) 
            {
                sum+=c;
                jian+=c;
            }
        }
        printf("Case #%d: %d\n",++ca,sum);
 
    }
    return 0;
}