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
#include<map>
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
struct node{
    float x,y;
    int num;
};
struct line{
    node a,b;
    float xie;
}L[10];
int l=0;
int cmp(node a,node b)
{
    if(a.y<b.y)
    return 1;
    if(a.x==b.x)
{   L[l].a=a;
    L[l].b=b;
    l++;        }
    return 0
}
int main()
{
    int n;
    node q[10005];
    while(scanf("%d\n",&n)==1)
    {  l=0;
      for(int i=0;i<n;i++)
      {
          scanf("%f%f",&q[i].x,&q[i].y);
          q[i].num=i;
      }
      sort(q,q+n,cmp);
      if(l!=0)
      {
        
      }

      else
      {
          for(int i=n-20;i>0 && i<n;i++)
          {
              for(int j=0;j<20 && j<i;j++)
              {
                  flaot xie=
              }
          }
      }
    }
    return 0;
}