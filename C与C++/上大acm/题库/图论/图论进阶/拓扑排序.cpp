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
int map[505][505];
int vis[505];

priority_queue<int,vector<int>,greater<int> > q;  
void topo(int n)  
{  
    for(int i=1;i<=n;i++)  
    {  
        if(vis[i]==0)  
            q.push(i);  
    }  
    int c=1;  
    while(!q.empty())  
    {  
        int v=q.top();  
        q.pop();  
        if(c!=n)  
        {  
            cout<<v<<" ";  
            c++;  
        }  
        else  
            cout<<v<<endl;  
        for(int i=1;i<=n;i++)  
        {  
            if(!map[v][i])  
                continue;  
            vis[i]--;  
            if(!vis[i])  
                q.push(i);  
  
        }  
    }  
}  
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        clr(vis,0);
        clr(map,0);
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            if(map[a][b]) 
            continue;
            map[a][b]=1;
            vis[b]++;
        }
        topo(n);
    }
    return 0;
}