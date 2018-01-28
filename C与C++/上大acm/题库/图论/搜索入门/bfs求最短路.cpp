#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int dp[100005];
int N,K;
struct node
{
  int x,step;
};
int check(int x)
{
    if(x<0 || x>=100005 || dp[x]) return 0;
    return 1;
}
int bfs(int x)
{
    int i;
    queue<node> Q;
    node a,next;
    a.x=x;
    a.step =0;
    dp[x]=1;
    Q.push(a);
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop();
        if(a.x == K) 
            return a.step;
         next =a ;
         next.x=a.x+1;
         if(check(next.x)) 
         {
             next.step = a.step+1;
             dp [next.x]=1;
             Q.push(next);
         } 
         next.x=a.x-1;
         if(check(next.x)) 
         {
             next.step = a.step+1;
             dp [next.x]=1;
             Q.push(next);
         } 
         next.x=a.x*2;
         if(check(next.x)) 
         {
             next.step = a.step+1;
             dp [next.x]=1;
             Q.push(next);
         } 
    }
    return -1;
}

int main()
{
  while(cin>>N>>K)
  {
      memset(dp,0,sizeof(dp));
      int ans=bfs(N);
      printf("%d\n",ans);
  }
    return 0;
}