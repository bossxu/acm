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
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
// 知识点分解：

int main()
{
    int t;
    cin>>t;
    while(t--)  
    {
        ll a;
        scanf("%lld",&a);
        ll k=sqrt(a/2);
        if(a==1)
        printf("4\n");
        else if(k*k*2==a)
        {
            printf("%d\n",4*k);
        }
        else
        {
           ll l=a-k*k*2;
           if(l<=k-1)
           {
            printf("%lld\n",4*k+1);
           }
           else 
           if(l>k-1&&l<=2*k)
           printf("%lld\n",4*k+2);
           else
           if(l>2*k)
           {
               if(l<=2*k+k)
                {
                   printf("%lld\n",4*k+3);
                }
                else
                {
                    printf("%lld\n",4*k+4);
                }
           }           
        } 
    }
    return 0;
}