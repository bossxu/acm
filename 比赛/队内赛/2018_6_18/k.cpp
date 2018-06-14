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
char s1[200005];
char s2[200005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
  scanf("%d",&t);
   while(t--)
   {
     scanf("%s",s1);
     scanf("%s",s2);
     int len = strlen(s1);
     //cout<<s1<<endl<<s2<<endl;
       int l = 0;int r = len-1;
       bool flag = 1;
       while( l<len && s1[l] == s2[l] ) l++;
       while(r>0 && s1[r] == s2[r]) r--;
       //cout<<l<<" "<<r<<endl;
       while(l<=r)
       {
         if(s1[l]!=s2[r] || s2[l]!=s1[r]) flag = 0;
         l++,r--;
       }
       if(flag) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
     }
  return 0;
}
