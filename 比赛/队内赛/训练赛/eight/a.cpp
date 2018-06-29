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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  std::ios::sync_with_stdio(false);
   int t,s,x;
   while(cin>>t>>s>>x){
   int flag = 0;
   if(t == x) flag = 1;
   int l = x-t;
   //cout<<l<<endl;
   if(l>0 && (l%s == 1 || l%s == 0)) flag = 1;
   if(l == 1) flag = 0;
   if(flag)
   {
     cout<<"YES"<<endl;
   }
   else
   cout<<"NO"<<endl;}
  return 0;
}
