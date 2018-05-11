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
int shu[200005];
int main()
{
  int n;
  int k;
  cin>>n>>k;
  for(int i = 1;i<=n;i++)
  {
    scanf("%d",&shu[i]);
  }
  sort(shu+1,shu+n+1);
  if(k == 0)
  {
    if(shu[1] == 1) cout<<"-1"<<endl;
    else cout<<shu[1]-1<<endl;
  }
  else{
  if(shu[k] == shu[k+1] && k!=n) cout<<"-1"<<endl;
  else cout<<shu[k]<<endl;}
  return 0;
}
