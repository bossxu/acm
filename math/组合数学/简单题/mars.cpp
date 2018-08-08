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

int gcd(int a,int b) {return b == 0?a:gcd(b,a%b);}

vector<int>q;
int main()
{
  int n,k;
  while(cin>>n>>k)
  {
    int op = k;
    for(int i = 1;i<=n;i++)
    {
          int a;
          cin>>a;
          a%=k;
          op = gcd(op,a);
    }
    q.clear();
    for(int i = 1;i<k;i++)
    {
      if(i%op == 0)
      {
        q.push_back(i);
      }
    }
    cout<<q.size()+1<<endl;
    cout<<0;
    for(int i = 0;i<q.size();i++)
    {
      cout<<" "<<q[i];
    }
    cout<<endl;
  }
  return 0;
}
