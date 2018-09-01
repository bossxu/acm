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
  int n;
  while(cin>>n)
  {
    std::vector<int> v;
    for(int i = 1;i<=n;i++)
    {
      int a;
      cin>>a;
      v.pb(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i = 0;i<v.size();i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
