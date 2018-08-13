#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
const int mod = 1e9+7;
const double eps = 1e-6;
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while(cin>>n)
  {
    int a,b,c,d;
    int num = 0;
    int flag = 0;
    for(int i = 1;i<=n;i++)
    {
      int sum = 0;
      cin>>a>>b>>c>>d;
      sum += a+b+c+d;
      if(i == 1)
      {
        num = sum;
      }
      if(sum > num) flag ++;
    }
    cout<<flag+1<<endl;
  }
  return 0;
}
