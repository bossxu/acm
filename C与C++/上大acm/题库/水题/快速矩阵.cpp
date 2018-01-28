#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include<math.h>
using namespace std;
typedef long long  ll;
ll N;
const ll mod=10000;

struct matrix      //我用一个结构体来存
{
      ll a[2][2];
}origin,res;          //顺便直接搞两个夺下赶出来。

void init()
{
    origin.a[0][0]=1;                   //原始的数组初始化。
    origin.a[0][1]=1;
    origin.a[1][0]=1;
    origin.a[1][1]=0;
     memset(res.a,0,sizeof(res.a));                        //归零话
     res.a[0][0]=res.a[1][1]=1;                  //将res.a初始化为单位矩阵
}
matrix multiply(matrix x,matrix y)                            //    矩阵的乘法
{
       matrix temp;
       memset(temp.a,0,sizeof(temp.a));
       for(int i=0;i<2;i++)
       {
               for(int j=0;j<2;j++)
               {
                       for(int k=0;k<2;k++)
                       {
                               temp.a[i][j]+=(x.a[i][k]*y.a[k][j])%mod;
                       }
               }
       }
       return temp;
}
void calc(int n)                             //核心的代码
{
     while(n)
     {
             if(n&1)
                    res=multiply(res,origin);
             n>>=1;
             origin=multiply(origin,origin);
     }
     /*for(int i=0;i<3;i++)
     {
             for(int j=0;j<3;j++)
                     printf("%8d",res.a[i][j]);
             printf("\n");
     }                                       //遍历的目的
     printf("\n");*/
}
int main()
{
    while(scanf("%lld",&N)==1 )
    {
       if(N<0) break;
        init();
        calc(N);
        printf("%lld\n",res.a[0][1]%mod);
    }
    return 0;
}

