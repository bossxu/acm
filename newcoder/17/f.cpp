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
typedef unsigned long long ll;
#define INF 0x3f3f3f3f
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
char s1[500005],s2[500005];
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int t;
   cin>>t;
   while(t--)
   {
     scanf("%s %s",s1,s2);
     int len1 = strlen(s1),len2 = strlen(s2);
     int cha = len1 - len2;
     int flag = 1;
     if(cha%2) flag = 0;

   }
  return 0;
}
