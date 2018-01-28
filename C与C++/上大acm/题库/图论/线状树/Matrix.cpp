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
// 知识点分解：二维树状数组
const int MAXN = 1005;
int treeNum[MAXN][MAXN];

int lowbit(int x){
    return x&(-x);
}

long long getSum(int x , int y){
    long long sum = 0;
    for(int i = x ; i > 0 ; i -= lowbit(i))
        for(int j = y ; j > 0 ; j -= lowbit(j))
            sum += treeNum[i][j];
    return sum;
}

void add(int x , int y , int val){
    for(int i = x ; i < MAXN ; i += lowbit(i))
        for(int j = y ; j < MAXN ; j += lowbit(j))
            treeNum[i][j] += val;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        clr(treeNum,0);
        scanf("%d%d",&n,&q);
        while(q--)
        {
            char c;
            getchar();
            scanf("%c",&c);
            if(c=='C')
            {
                int a,b,c,d;
                scanf("%d%d%d%d",&a,&b,&c,&d);
                add(a,b,1);
                add(a,d+1,-1);
                add(c+1,b,-1);
                add(c+1,d+1,1);
            }
            else
            {
              int a,b;
               scanf("%d%d",&a,&b);
              ll k =getSum(a,b);
              if(k%2==0 ) printf("0\n");
              else printf("1\n");
            }
        }
        cout<<endl;
    }
    return 0;
}