#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include<math.h>
using namespace std;
typedef long long  ll;
ll N;
const ll mod=10000;

struct matrix      //����һ���ṹ������
{
      ll a[2][2];
}origin,res;          //˳��ֱ�Ӹ��������¸ϳ�����

void init()
{
    origin.a[0][0]=1;                   //ԭʼ�������ʼ����
    origin.a[0][1]=1;
    origin.a[1][0]=1;
    origin.a[1][1]=0;
     memset(res.a,0,sizeof(res.a));                        //���㻰
     res.a[0][0]=res.a[1][1]=1;                  //��res.a��ʼ��Ϊ��λ����
}
matrix multiply(matrix x,matrix y)                            //    ����ĳ˷�
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
void calc(int n)                             //���ĵĴ���
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
     }                                       //������Ŀ��
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

