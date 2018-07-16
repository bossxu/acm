#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N,P;
  while(cin>>N>>P)
  {
      double ans=P*1.0/(N+1);
      double now=ans;
      for(int i=2;i<=1000000;i++)
      {
        now*=(N*1.0-P+(i));
        now/=(N*1.0+i);
        now/=(i*1.0-1);
        now*=i*1.0;
        //printf("%.7f\n",now);
        ans=max(ans,now);
      }
      printf("%.8f\n",ans);
  }
  return 0;
}
