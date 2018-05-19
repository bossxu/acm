#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
ll c[105],v[105];
ll cal[10005];
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n; ll land;
    cin>>n>>land;
    clr(cal,INF);
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {
      cin>>c[i]>>v[i];
      sum+=v[i];
    }
    cal[0] = 0;
    //cout<<sum<<endl;
    for(int i = 1;i<=n;i++)
    {
      for(int j = sum;j>=v[i];j--)
      {
        cal[j] = min(cal[j],cal[j-v[i]]+c[i]);
      }
    }
    for(int i = sum;i>=0;i--)
    {
      if(cal[i]<=land)
      {
        cout<<i<<endl;
        break;
      }
    }
  }
  return 0;
}
