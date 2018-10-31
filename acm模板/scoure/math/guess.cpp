#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int MOD = 7;
const int MAXN = 50;
int a[MAXN][MAXN];//增广矩阵 就是那个方程组左边的东西
int x[MAXN];//解集  这个是那个
bool free_x[MAXN];//标记是否是不确定的变元
inline int gcd(int a,int b)
{
    int t;
    while(b!=0)
    {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}
inline int lcm(int a,int b)
{
    return a/gcd(a,b)*b;//先除后乘防止溢出
}
//高斯消元法接方程组。(-2表示有浮点数解,但无整数解,-1表示无解,
//0表示唯一解,大于0表示无穷解,并返回自由变元的个数)
//有equ个方程,var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var
int Gauss(int equ,int var)
{
    int i,j,k;
    int max_r;//当前这列绝对值最大的行
    int col;//当前处理的列
    int ta,tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;

    for(int i = 0;i <= var;i++)
    {
        x[i] = 0;
        free_x[i] = true;
    }
    //转换为阶梯阵
    col = 0;//处理当前的列
    for(k = 0;k<equ && col<var;k++,col++)
    {//枚举当前处理的行,找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r = k;
        for(i = k+1;i < equ;i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        if(max_r!=k)
        {//与第k行交换
            for(j = k;j < var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {//说明该col列第k行一下全是0了,则处理当前行的下一列
            k--;
            continue;
        }
        for(i = k+1;i < equ;i++)
        {//枚举要删去的行
            if(a[i][col]!=0)
            {
                LCM = lcm(abs(a[i][col]),abs(a[k][col]));
                ta = LCM/abs(a[i][col]);
                tb = LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col] < 0) tb = -tb;//异号的情况是相加
                for(j = col;j < var+1;j++)
                {
                    a[i][j] = ((a[i][j]*ta-a[k][j]*tb)%MOD+MOD)%MOD;
                }
            }
        }
    }
    //Debug();
    //1.无解的情况：化简的增广阵中存在(0,0,...,a)这样的行(a!=0)
    for(i = k;i < equ;i++)
    {//对于无穷解来说,如果要判断哪些是自由变元,那么初等行变换中的交换就会影响,则要记录交换
        if(a[i][col]!=0) return -1;
    }
    //2.无穷解的情况：在var*(var+1)的增广阵中出现(0,0,...,0)这样的行,说明没有形成严格的上三角阵
    //且出现的行数即为自由变元的个数
    if(k < var)
    {
        //首先自由变元有(var-k)个,即不确定的变元至少有(var-k)个
        for(i = k-1;i>=0;i--)
        {
            //第i行一定不会是(0,0,...,0)的情况,因为这样的行是在第k行到第equ行
            //同样,第i行一定不会是(0,0,...,a),a!=0的情况,这样的无解的
            free_x_num = 0;//用于判断该行中不确定的变元的合数,如果超过1个,则无法求解,他们仍然为不确定的变元
            for(j = 0;j < var;j++)
            {
                if(a[i][j]!=0 && free_x[j]) free_x_num++,free_index = j;
            }
            if(free_x_num > 1) continue;//无法求解出确定的变元
            //说明就只有一个不确定的变元free_index,那么可以求解出该变元,且该变元是确定的
            temp = a[i][var];
            for(j = 0;j < var;j++)
            {
                if(a[i][j]!=0 && j!= free_index) temp -= a[i][j]*x[j]%MOD;
                //temp -= (temp%MOD+MOD)%MOD;
            }
            //while(temp%a[i][free_index]!=0) temp+=MOD;
            x[free_index] = (temp/a[i][free_index])%MOD;//求出该变元
            free_x[free_index] = 0;//该变元是确定的
        }
        return (var-k);//自由变元有(var-k)个
    }
    //3.唯一解的情况：在var*(var+1)的增广阵中形成严格的上三角阵
    //计算出Xn-1,Xn-2,...,X0
    for(i = var-1;i>=0;i--)
    {
        temp = a[i][var];
        for(j = i+1;j<var;j++)
        {
            if(a[i][j]!=0) temp -= a[i][j]*x[j];
            //temp = (temp%MOD+MOD)%MOD;
        }
        //while(temp%a[i][j]!=0) temp+=MOD;
        //if(temp%a[i][i]!=0) return -2;
        x[i] = temp/a[i][i];
    }
    return 0;
}
int main()
{
    int i,j;
    int equ,var; // 方程数和未知解个数
    while(scanf("%d %d",&equ,&var)==2)
    {
        memset(a,0,sizeof(a));
        for(i = 0;i < equ;i++)
        {
            for(j = 0;j < var+1;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        //Debug();
        int free_num = Gauss(equ,var);
        if(free_num == -1) printf("No solution\n");
        else if(free_num == -2) printf("Float but no int solution\n");
        else if(free_num > 0)
        {
            printf("Infinite solution,自由变元个数为%d\n",free_num);
            for(i = 0;i < var;i++)
            {
                if(free_x[i]) printf("x%d 是不确定的\n",i+1);
                else printf("x%d: %d\n",i+1,x[i]);
            }
        }
        else
        {
            for(i = 0;i < var;i++)
            {
                printf("x%d: %d\n",i+1,x[i]);
            }
        }
        printf("\n");
    }
    return 0;
}



// 上面的那个适用于求整数解，下面放一个适用于浮点数的例子
// op是那个矩阵  ， dp 是后面的值
// 算完后，dp里面的值是答案，这个有一个缺陷，这个只适用于一定有解的情况。
//langman
#include<bits/stdc++.h>
using namespace std;

#define clr(shu,x) memset(shu,x,sizeof(shu))
#define INF 0x3f3f3f3f
#define pi acos(-1)
#define loge exp(1)
#define ll long long
#define pb push_back
#define ios_close ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int mod = 1e9+7;
const double eps = 1e-6;
char shu[20][20];
double dp[230]; // 这个表示的是现在这个点到终点的期望
double op[230][230];
int n,m;
int cal(int i,int j)  //算出一维坐标
{
  return (i-1)*m+j;
}
bool check(int i,int j)
{
  if(i<1 || j <1 || i>n || j>m || shu[i][j] == '#') return false;
  return true;
}
int num(int i,int j)
{
  int tot = 0;
  if(check(i+1,j)) tot++;
  if(check(i,j+1)) tot++;
  if(check(i-1,j)) tot++;
  if(check(i,j-1)) tot++;
  return tot;
}
bool tag;
int vis[20][20];
void dfs(int x,int y)
{
  if(shu[x][y] == '$') tag = 1;
  vis[x][y] = 1;
  for(int dx = -1;dx<=1;dx++)
  {
    for(int dy = -1;dy <= 1;dy++)
    {
      if(dx == dy || dx+dy == 0) continue;
      if(check(x+dx,y+dy) && !vis[x+dx][y+dy])
          dfs(x+dx,y+dy);
    }
  }

}
int main()
{
//  ios_close;
  while(scanf("%d%d",&n,&m) == 2)
  {
    clr(dp,0);
    clr(op,0);
    clr(vis,0);
    int a,b;
    int x,y;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        scanf("%c",&shu[i][j]);
        if(shu[i][j] == '$') b = cal(i,j);
        if(shu[i][j] == '@') a = cal(i,j),x = i,y = j;
      }
    }
    dfs(x,y);
    if(tag == 0)
    {
      printf("-1\n");
      continue;
    }
    op[b][b] = 1;
    dp[b] = 0;
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=m;j++)
      {
        int tot = num(i,j);
        if(shu[i][j] == '$') continue;
        if(tot == 0)
        {  dp[cal(i,j)] = INF;  continue; }
        op[cal(i,j)][cal(i,j)] = 1;
        if(check(i+1,j)) op[cal(i,j)][cal(i+1,j)] = -1.0/tot;
        if(check(i,j+1)) op[cal(i,j)][cal(i,j+1)] = -1.0/tot;
        if(check(i-1,j)) op[cal(i,j)][cal(i-1,j)] = -1.0/tot;
        if(check(i,j-1)) op[cal(i,j)][cal(i,j-1)] = -1.0/tot;
      }
    }

  }
  return 0;
}
