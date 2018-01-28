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
int cmp(int a, int b)
{
  if(a>b) return 1;
  return 0;
}
int main()
{
  int n,k;
  int a[3005];
  while(scanf("%d%d",&n,&k)==2)
  {
      for(int i=0;i<n;i++)
      {
         cin>>a[i];   
      }
      sort(a,a+n,cmp);
      int s[10002],ca=0;
      for(int i=0;i<100 && i<n;i++)
      {
          for(int j=i+1;j<100 && j<n;j++)
          {
             s[ca++]=a[i]+a[j];
          }
      }
      sort(s,s+ca,cmp);
      for(int i=0;i<k-1;i++)
      {
          printf("%d ",s[i]);
      }
      printf("%d\n",s[k-1]);
  }
    return 0;
}