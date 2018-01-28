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
struct Lu{
  int x,y;
}node[3005],tree[3005];
vector<int>map[3005];
vector<int>fu[3005];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&n);
      int a;
      int c2=0,c1=0;
      for(int i=1;i<=n;i++)
      {
          map[i].clear();
          fu[i].clear();
      }
      for(int i=1;i<n;i++)
      {
          int k=0;
          int p=0;
          for(int j=1;j+i<=n;j++)
          {
            scanf("%d",&a);
            if(a==0 && c1!=1)
            {
               for(int l=0;l<map[i].end()-map[i].begin();l++)
               {
                   if(map[i][l]>j+i) break;
                   if(map[i][l]==j+i)
                   {c1=1;} 
                }
               Lu A;
               A.x=i,A.y=i+j;
               node[k++]=A;
            }
            if(a==1 && c2!=1)
            {
                for(int l=0;l<fu[i].end()-fu[i].begin();l++)
                {
                    if(fu[i][l]>i+j) break;
                    if(fu[i][l]==j+i)
                    {
                        c2=1;
                    } 
                }
                Lu A;
                A.x=i,A.y=i+j;
                tree[p++]=A;
            }
          }
         for(int z=0;z<k && c1!=1;z++)
          {
              for(int c=z+1;c<k;c++)
              {
                 map[node[z].y].push_back(node[c].y);
              }
          }
          for(int z=0;z<p && c2!=1;z++)
          {
              for(int c=z+1;c<p;c++)
              {
                 fu[tree[z].y].push_back(tree[c].y);
              }
          }
      }
          if(c1==1 || c2==1)
          {
              printf("Bad Team!\n");
          }
          else
          {
              printf("Great Team!\n");
          }
    }
    return 0;
}