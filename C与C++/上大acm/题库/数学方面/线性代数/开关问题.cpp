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
#define MAXN 35
void swap(int &a,int &b){  
    int t = a;  
    a = b;  
    b = t;  
}  
int n;
struct Matrix{  
    int mp[MAXN][MAXN];  
    void rswap(int x,int y){//将x行的元素与y行的元素互换  
        for(int j = 1; j <= n+1; j++){  
            swap(mp[x][j],mp[y][j]);  
        }  
    }  
    void relax(int x, int y){//用x行的元素消掉y行的元素，一般为第一个非零元  
        for(int j = 1; j <= n+1; j ++){  
            mp[y][j] ^= mp[x][j];  
        }  
    }  
    void init(){//初始化  
        memset(mp,0,sizeof(mp));  
        for(int i = 1; i <= n ;i++){//自己可以改变自己  
            mp[i][i] = 1;  
        }  
    }  
}M;    
void Gauss(){  // 把矩阵变成了   行阶梯形   并且求矩阵的制
    int i, j, k, ptr;  
    for(i = 1, j= 1; j <= n; ++i, ++j){//形成行阶梯型矩阵，从第一行第一列开始，逐列递增  
        for(ptr = i; ptr  <= n ; ptr++){//找出第一个是非零元的行  
            if(M.mp[ptr][j]){  
                break;  
            }  
        }  
        if(ptr == n+1){//如果这一列所有行都是零元，则跳过这一列  
            --i;  
            continue;  
        }  
        if(ptr != i){//如果第一个是非零元的行不是当前行，则与其互换位置  
            M.rswap(ptr,i);  
        }  
        for(k = i+1; k <= n; k++ ){//用当前的行当前列的值对下面所有行当前列的值进行消除，使其为0，以满足行阶梯型  
            if(!M.mp[k][j]){//如果是0，则跳过  
                continue;  
            }  
            M.relax(i,k);//不是，则消除。  
        }  
    }
    // 此刻记录的i 就是第几行开始，已经全部都是0 了
    for( k = i; k <= n; k++){//处理完所有列（为n，n+1为答案列不用计算）之后，也就是现在mp数组就是行阶梯型了，那么看零行的答案是否都为0，有不为0，即是无解。  
        if(M.mp[k][n+1] != 0){  
            printf("Oh,it's impossible~!!\n");  
            return ;  
        }  
    }  
  
    printf("%d\n",1<<(n-i+1));//有多少零行就有多少自由元，输出结果  
    return;    
}
int main()
{
    int t;
    cin>>t;
    int a[50];
    int e[50];
    while(t--)
    {
       cin>>n;
       M.init();
       for(int i=1;i<=n;i++) 
         cin>>a[i];
       for(int i=1;i<=n;i++)
         cin>>e[i];
       for(int i=1;i<=n;i++)
         M.mp[i][n+1]=a[i]^e[i];   
      int x,y;
      while(scanf("%d%d",&x,&y)==2 && (x||y))
      {
          M.mp[y][x]=1;
      }
      Gauss();
       
    }
    return 0;
}