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
#include<map>
#include<cstdlib>
#include<functional>
#include<climits>
#include<cctype>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
const int maxn = 1e6+5;
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
char a[maxn];
int ji[maxn];

int main()
{
  int n, co = 0;
  while(scanf("%d",&n)==1 && n)
  {
    scanf("%s",a);
    ji[0]=0,ji[1]=0;
    for(int i=1;i<n;i++)
    {
        int j=ji[i];
        while(j && a[i]!=a[j]) j=ji[j];
        ji[i+1]=(a[i]==a[j] ? j+1:0) ; 
    }
    printf("Test case #%d\n",++co);
   /* for(int i=1;i<=n;i++)
    {
        printf("ji[%d]==%d \n",i,ji[i]);
    }*/
    for( int i=2;i<=n;i++)
    {
        if(ji[i]>0 && i%(i-ji[i])==0) printf("%d %d\n",i,i/(i-ji[i]));
    }
    putchar('\n');
  }    
    return 0; 
}