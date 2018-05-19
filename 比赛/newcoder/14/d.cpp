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
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
   int n;
   int shu[105];
   while(cin>>n)
   {
     for(int i =1;i<=n;i++)
     {
       cin>>shu[i];
     }
     if(shu[n] == 0 )
     {
       cout<<"UP"<<endl;
       continue;
     }
     if(shu[n] == 15)
     {
       cout<<"DOWN"<<endl;
       continue;
     }
     if(n == 1)
     {
       cout<<-1<<endl;
       continue;
     }
    if(shu[n-1]>shu[n])
    {
      cout<<"DOWN"<<endl;
    }
    else
    {
      cout<<"UP"<<endl;
    }
   }
  return 0;
}
