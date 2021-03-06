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
char s1[200005];
char s2[200005];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   scanf("%s",s1);
   scanf("%s",s2);
   int len1 = strlen(s1);
   int len2 = strlen(s2);
   int flag = 1;
   int id1 = 0,id2 = 0;
   while(id1<len1 && flag)
   {
     if(s1[id1] == s2[id2] && id1<len1 && id2<len2)
     {
       id1++,id2++;
       continue;
     }
     if(id2 == len2) id2--;
     while(s1[id1] != s2[id2])
     {
       //cout<<s1[id1]<<" "<<s2[id2]<<endl;
       id2--;
       if(id2<0) {flag = 0;break;}
     }

   }
   if(flag && id2 == len2) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
  return 0;
}
