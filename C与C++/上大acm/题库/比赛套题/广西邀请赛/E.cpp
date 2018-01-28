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
// 知识点分解：
int main()
{
    int n,q;
    int a[100005];
    int b[32],c[32],d[32],e[32];
    while(cin>>n>>q)
    {
        int s=0;
        clr(b,0);
        clr(c,0);
        for(int i=1;i<=n;i++)
        {
           cin>>a[i];
           int k=a[i];
           s^=k;
           for(int j=0;j<32;j++)
           {
               if(k%2)
               {
                   b[j]++;
               }
               else
               {
                   c[j]++;
               }
               k/=2;
           }
        }
        for(int o=1;o<=q;o++)
        {
            clr(d,0);
            clr(e,0);
            int z;
            cin>>z;
            int p=a[z];
            for(int i=0;i<32;i++)
            {
                if(p%2)
                {
                    d[i]++;
                }
                else
                {
                    e[i]++;
                }
                p/=2;
            }
            int l=0,w=0;
            for(int i=31;i>=0;i--)
            {
               if(c[i]-e[i]==0)
               l=l*2+1;
               else
               l=l*2; 
            }
            printf("%d ",l);
            for(int i=31;i>=0;i--)
            {
                if(b[i]-d[i]==0)
                {
                    w=w*2;
                }
                else
                {
                    w=w*2+1;
                }
            }
            printf("%d ",w);
            printf("%d\n",s^a[z]);   
        }  
    }
    return 0;
}