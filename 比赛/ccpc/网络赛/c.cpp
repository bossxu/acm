#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;


int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int p;
    scanf("%d",&p);
    if(p == 2)
    {
      printf("0 1\n");
      printf("1 0\n");
      printf("0 0\n");
      printf("0 1\n");
    }
    else
    {
      for(int i = 0;i<p;i++)
      {
        if(i == 0)
        {
          printf("0");
          for(int j = 1;j<p;j++)
          {
            printf(" %d",j);
          }
          printf("\n");
          continue;
        }
        printf("%d",i);
        for(int j = 1;j<p;j++)
        {
          printf(" 0");
        }
        printf("\n");
      }
      for(int i = 0;i<p;i++)
      {
          printf("0");
          for(int j = 1;j<p;j++)
          {
            printf(" %d",j*i%p);
          }
          printf("\n");
      }
    }
  }
  return 0;
}
