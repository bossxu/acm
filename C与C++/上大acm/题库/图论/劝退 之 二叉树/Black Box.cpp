#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define maxn 30005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
struct cmp1{  
    bool operator ()(int &a,int &b){  
        return a>b;//最小值优先  
    }  
};  
int main()
{
    int a[maxn],b[maxn];
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&b[i]);
        }
        priority_queue<int,vector<int>,cmp1>q;
        priority_queue<int>q2;
        int j=1,o=0;q2.top()=-INF;
        for(int i=1;i<=k;i++)
        {
            while(j<=b[i])
             {if(a[j++]>q2.top())
              q.push(a[j]);
              else 
              q2.push(a[j]);
              o++;}
              int c=i,tmp;
              if(c<=o)
              {
                tmp = q2.top();
                q2.pop();
              }
              if(c>o)
             {
                 c-=o; 
                 while(--c)
              {
                q2.push(q.top());
                o++;
                q.pop();
              }
             
             tmp= q.top();
             }
            printf("%d\n",tmp); 
        }
    }
}