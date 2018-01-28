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
// 知识点分解：RMQ 
// 区间最大最小值的查询
const int N = 50005;  
int FMAX[N][20], FMIN[N][20];  
  
void RMQ(int n)  //模版预处理
{  
    for(int j = 1; j != 20; ++j)  
    {  
        for(int i = 1; i <= n; ++i)  
        {  
            if(i + (1 << j) - 1 <= n)  
            {  
                FMAX[i][j] = max(FMAX[i][j - 1], FMAX[i + (1 << (j - 1))][j - 1]);  
                FMIN[i][j] = min(FMIN[i][j - 1], FMIN[i + (1 << (j - 1))][j - 1]);  
            }  
        }  
    }  
}  
int main()
{
    int n,q;
    while(cin>>n>>q)
    {
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            FMAX[i][0]=a;
            FMIN[i][0]=a;
        }
        RMQ(n);
        while(q--)
        {
            int a,b;
            scanf("%d%d", &a, &b);  
            int k = (int)(log(b - a + 1.0) / log(2.0));  
            int maxsum = max(FMAX[a][k], FMAX[b - (1 << k) + 1][k]);  
            int minsum = min(FMIN[a][k], FMIN[b - (1 << k) + 1][k]);  
            printf("%d\n", maxsum - minsum);  
        }
    }
    return 0;
}