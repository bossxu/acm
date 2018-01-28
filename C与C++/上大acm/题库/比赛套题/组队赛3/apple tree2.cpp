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
const int N = 110000;
vector<vector<int> > a(N);  
int n,m,lef[N],rig[N],c[N],tot,s[N];  
#define lowbit(x) (x&-x)  
int sum(int x)  
{  
    int ret = 0;  
    while(x>0)  
    {  
        ret+=c[x];  
        x-=lowbit(x);  
    }  
    return ret;  
}  
  
void add(int x,int d)  
{  
    while(x<=n)  
    {  
        c[x]+=d;  
        x+=lowbit(x);  
    }  
}    
void dfs(int x)  
{  
    lef[x] = tot;  
    for(int i = 0; i<a[x].size(); i++)  
    {  
        tot++;  
        dfs(a[x][i]);  
    }  
    rig[x] = tot;  
}  
int main()  
{  
    int i,j,k,x,y;  
    char op[5];  
    while(scanf("%d",&n)==1)  
    {  
        clr(lef,0);  
        clr(rig,0);  
        clr(s,0);  
        clr(c,0);  
        for(i=0; i<N; i++)  
            a[i].clear();  
        for(i = 1; i<n; i++)  
        {  
            scanf("%d%d",&x,&y);  
            a[x].push_back(y);  
        }  
        tot = 1;  
        dfs(1);  
        for(i = 1; i<=n; i++)  
        {  
            s[i] = 1;  
            add(i,1);  
        }  
        scanf("%d",&m);  
        while(m--)  
        {  
            scanf("%s%d",op,&x);  
            if(op[0]=='Q')  
            {  
                printf("%d\n",sum(rig[x])-sum(lef[x]-1));  
            }  
            else  
            {  
                if(s[x])  
                    add(lef[x],-1);  
                else  
                    add(lef[x],1);  
                s[x]=!s[x];  
            }  
        }  
    }  
    return 0;  
}  