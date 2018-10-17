#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define clr(shu,x) memset(shu,x,sizeof(shu))
const int mod = 1e9+7;
const double eps = 1e-6;
const double pi = acos(-1);
#define pb push_back
const int INF = 0x3f3f3f3f;
const int N = 1000;
double A[N];
double B[N];
// 这个题 读错了题，他是刚好为a，b，c的时候分数清空，所以这里的每一个公式的推导，并不是可以直接出的
// 而是要去建立方程，然后去算。
// 很多的时候是方程迭代求解。
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int t; scanf("%d",&t);
  while(t--)
  {
    int n;
    int k1,k2,k3;
    int a,b,c;
    clr(A,0);
    clr(B,0);
    scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
    double ji = 1.0/k1/k2/k3;
    //printf("%.4lf\n",ji);
    for(int i = n;i>=0;i--)
    {
      for(int j = 1;j<=k1;j++)
      {
        for(int l = 1;l<=k2;l++)
        {
          for(int o = 1;o<=k3;o++)
          {
            if(j == a && l == b && o ==c) continue;
            A[i] += ji*A[i+(j+l+o)];
            B[i] += ji*B[i+j+l+o];
          }
        }
      }
      A[i] += ji;
      B[i] += 1;
    }
    printf("%.9lf\n",B[0]/(1-A[0]));
  }

  return 0;
}
