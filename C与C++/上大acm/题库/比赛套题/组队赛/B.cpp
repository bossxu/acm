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
#define mod 1e9+7
#define clr(a,x) memset(a,x,sizeof(a))
const double eps = 1e-6;
// 知识点分解：
int main()
{
    int num[105];
    int n;
    while(cin>>n && n)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            sum^=num[i];
        }
        if(sum==0)
        printf("0\n");
        else
        {
            int a=0;
            for(int i=1;i<=n;i++)
            {
                if(num[i]> (num[i]^sum))
                a++;
            }
            printf("%d\n",a);
        }
    }
    return 0;
}