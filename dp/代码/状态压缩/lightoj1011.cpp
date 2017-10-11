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
int val[1<<16],suit[1<<16];
int map[16][16];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,co = 0;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      for(int i = 0;i<n;i++)
       for(int j = 0;j<n;j++)
        cin>>map[i][j];

      clr(val,0);
      clr(suit,0);
      for(int i = 0;i<1<<n;i++)
      {
        for(int j = 0; j<n;j++ )
        {
          if( (1<<j) & i)
          continue;
          int t=0;
          int z;
          for(int k = 0;k<n;k++)
          {
            if(suit[i] & (1<<k))
            continue;
            if(t<map[j][k]+val[i])
            {
              t = val[i]+map[j][k];
              z = suit[i]|(1<<k);
            }
          }
          if(t > val[i | (1<<j)])
          {
            val[i|(1<<j)] = t;
            suit[i|(1<<j)] = z;
          }
        }

      }
      printf("Case %d: %d\n",++co,val[(1<<n)-1]);
   }
    return 0;
}
