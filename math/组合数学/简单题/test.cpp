//传送门：http://acm.hdu.edu.cn/showproblem.php?pid=6030
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
#define LL long long
#define N 10
#define M 2005
#define INF 0x3f3f3f3f
const double eps = 1e-10;
const int mod = 1e9 + 7;
/*
题意：长度为n的串，对每一段长度为素数的子串，都满足红色不少于蓝色
其实就是 长度为2和3的子串 红色 不少于 蓝色
所以只要管最后两个的颜色就好，0代表蓝 红代表1
01  可以转移 到 011，末尾变为 11
10  可以转移 到 101，末尾变为 01
11  可以转移 到 110，末尾变为 10,
11也可以转移 到 111，末尾变为 11
所以有初始 答案矩阵 1 1 1
       01    关系矩阵 0 0 1
       10             1 0 0
       11             0 1 1
*/
struct matrix
{
    LL a[N][N];
    matrix(){
    memset(a,0,sizeof(a));
    }
};
matrix pow(matrix b,matrix a)
{
    matrix c;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(a.a[i][j]==0) continue;
          for(int k=1;k<=3;k++){
            c.a[i][k] = (c.a[i][k] + a.a[i][j] * b.a[j][k]) % mod;
          }
        }
    }
    return c;
}
matrix pow_matrix(LL n,matrix a)
{
    matrix b;
    b.a[1][3] = b.a[2][1] = b.a[2][2]= b.a[3][2] = 1;
    while(n){
        if(n&1) a = pow(b,a);
        b = pow(b,b);
        n>>=1;
    }
    return a;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        LL n;
        scanf("%lld",&n);
        if(n==2) printf("3\n");
        else{
            matrix ans;
            ans.a[1][1] = ans.a[1][2] = ans.a[1][3] = 1;
            ans = pow_matrix(n-2,ans);
            printf("%lld\n",(ans.a[1][1]+ans.a[1][2]+ans.a[1][3])%mod);
        }
    }
}
