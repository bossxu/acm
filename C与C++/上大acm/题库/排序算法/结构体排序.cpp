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
    char a[12];
    int num;
}node[20];
int cmp(st b ,st c)
{
    if(c.num<b.num) return 1;
    return 0;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",&node[i].a,&node[i].num);
        }
        sort(node,node+n,cmp);
        for(int i=0 ;i<n-1;i++)
        {
            printf("%s ",node[i].a);
        }
        printf("%s\n",node[n-1].a);
    }
    return 0;
}