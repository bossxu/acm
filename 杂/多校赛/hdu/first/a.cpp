#include<bits/stdc++.h>
using namespace std;
//const int N = 1e6+5;
#define ll long long
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
//  init();
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    if(n%3 == 0)
    {
      cout<<1LL*(n/3)*(n/3)*(n/3);
    }
    else if(n%4 == 0)
    {
      cout<<1LL*(n/2)*(n/4)*(n/4);
    }
    else
      cout<<-1;
      cout<<endl;
  }
  return 0;
}
