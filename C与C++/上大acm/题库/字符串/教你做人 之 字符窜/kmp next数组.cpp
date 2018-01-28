#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
const int maxn = 1e6+5;
char a[maxn];
int ne[maxn],ans[maxn];

int main()
{ 
    int T;
    cin>>T;
    int co =0;
    while(T--)
    {
      scanf("%s",a);
      int n=strlen(a);
     ne[0]=0,ne[1]=0;
     int j,k;
    for(int i=1;i<n;i++)
    {
        int j=ne[i];
        while(j && a[i]!=a[j]) j=ne[j];
        ne[i+1]=(a[i]==a[j] ? j+1:0) ; 
    }
    for(int i = 1;i<=n;i++) printf("  %d\n",ne[i]);
    for(k=0,j=n;j>0;j=ne[j])
    {
      ans[k++]=n-ne[j];
    }
    printf("Case #%d: %d\n",++co,k);
    for(j=0;j<k;j++)
    {
        printf("%d%c",ans[j],j==k-1?'\n':' ');
    }
    }
            return 0;
}