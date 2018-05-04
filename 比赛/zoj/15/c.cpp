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
char s[200];
int gcd(int a,int b)
{
  return b == 0?a:gcd(b,a%b);
}
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   int shu[20];
   while(t--)
   {
     clr(shu,0);
     int n;
     cin>>n;
     gets(s);
     for(int i = 0;i<strlen(s);i++)
     {
       if(s[i] == ' ') continue;
       if(s[i] == 'A') shu[1]++;
       if(s[i] == 'J') shu[11]++;
       if(s[i] == 'Q') shu[12]++;
       if(s[i] == 'k') shu[13]++;
       if(s[i] == '1') shu[10]++;
       if(s[i]<='9' && s[i]>'1') shu[s[i]-'0']++;
     }
     cout<<1;
     for(int i = 2;i<=12;i++)
     {
       if(shu[i] == 4) cout<<" 1";
       else if(shu[1] == 4) cout<<" 0";
       else {
         int a = 4-shu[1],b = 8-shu[1]-shu[i];
         int k = gcd(a,b);
         a/=k,b/=k;
         cout<<" "<<a<<"/"<<b;}
     }
     cout<<endl;
   }
  return 0;
}
