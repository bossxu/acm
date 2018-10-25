#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
map<int,int>dp[maxn];
map<int,int>::iterator it,it2;
int main()
{
  int n,m;
  while(cin>>n>>m)
  {
    int ans=0;
    for(int i=1;i<=m;i++)
    {
      int a,b,w;
      cin>>a>>b>>w;
      dp[a][-1]=0;dp[b][-1]=0;
      it=dp[a].lower_bound(w);
       it--;
     it2=dp[b].upper_bound(w);
     it2--;
      int cnt=it->second+1;
      //if(it2->second>cnt) continue;
      if(it2->second>=cnt) continue;
      dp[b][w]=cnt;
      ans=max(ans,cnt);
      it2=dp[b].upper_bound(w);
      // cout<<a<<" "<<b<<" "<<ans<<endl;
     for(;it2!=dp[b].end();)
       {
         // cout<<"*"<<it->first<<" "<<it->second<<endl;
         if(it2->second<=cnt)
            it2=dp[b].erase(it2);
          else break;
       }
    }
    cout<<ans<<endl;
  }
}
