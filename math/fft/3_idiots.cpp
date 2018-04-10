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
#define PI acos(-1)
#define loge exp(1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
struct complex
{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0)
    {
        r = _r; i = _i;
    }
    complex operator +(const complex &b)
    {
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b)
    {
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b)
    {
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
const int MAXN = 300010;
complex x1[MAXN];//这一个是第一个多项式的系数，第二个是第二个多项式的系数
ll shu[MAXN/2];//这是未处理的输入字符
ll sum[MAXN];//这是答案所放的位置
ll dp[MAXN];
void change(complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    scanf("%d",&n);
    int a,maxn = 0;
    clr(shu,0);
    clr(dp,0);
    for(int i = 1;i<=n;i++)
    {
      scanf("%d",&a);
      shu[a]++;
      maxn = max(maxn,a);
    }
    int len = 1;
    while(len < 2*maxn) len<<=1;
    for(int i = 0;i<=maxn;i++)
    {
      x1[i] = complex(shu[i],0);
    }
    for(int i = maxn+1;i<len;i++)
    {
      x1[i] = complex(0,0);
    }
    fft(x1,len,1);
    for(int i = 0;i<len;i++)
    x1[i] = x1[i]*x1[i];
    fft(x1,len,-1);
    for(int i = 1;i<=maxn;i++)
    {
      sum[i] = (ll)(x1[i].r+0.5);
    }
    for(int i = 2;i<=maxn;i++)
    {
      if(i%2 == 0)
      {
        sum[i] -= shu[i/2];
      }
      sum[i]/=2;
      //cout<<i<<"->"<<sum[i]<<endl;
    }
    for(int i = maxn;i>=1;i--)
    {
      dp[i] = dp[i+1]+shu[i];
    }
    ll num = 0;
    for(int i = 2;i<=maxn;i++)
    {
      if(sum[i]>0)
      {
        num += sum[i]*(dp[i]);
      }
    }
    ll fenmu = (ll)n*(n-1)*(n-2)/6;

    printf("%.7lf\n",(double)(fenmu-num)/fenmu);
  }
  return 0;
}
