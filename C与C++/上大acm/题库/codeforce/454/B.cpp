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
const int mod = 1e9+7 ;
#define clr(a,x) memset(a,x,sizeof(a))
#define cle(a,n) for(int i=1;i<=n;i++) a.clear();
const double eps = 1e-6;
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  char map[20][20];
      int x,y;
    for(int i = 1;i<=9;i++)
    {
      gets(map[i]);
      if(i%3 == 0 && i!=9)
      getchar();
    }
    cin>>x>>y;
    int flag = 0;
    char mas[10][10];
    for(int i = 1;i<=9;i++)
    {
      int size = 1;
      for(int j = 0;j<11;j++)
      {
        if(j == 3 || j == 7) continue;
        mas[i][size++] = map[i][j];
      }
    }
    x%=3,y%=3;
    x = x==0?3:x;
    y = y==0?3:y;
    for(int i = 3*x;i>3*(x-1);i--)
    {
      for(int j = 3*y;j>3*(y-1);j--)
      {
        //cout<<"->"<<i<<j<<endl;
        if(mas[i][j] == '.')
        {
          flag = 1;
          mas[i][j] = '!';
        }
      }
    }

    if(!flag)
    {
      for(int i = 1;i<=9;i++)
      {
        for(int j = 1;j<=9;j++)
        {
          if(mas[i][j] == '.')
          cout<<'!';
          else
          cout<<mas[i][j];
          if(j == 3|| j == 6)
          cout<<' ';
        }
        cout<<endl;
        if(i%3 == 0)
        cout<<endl;
      }
    }
    else
    {
      for(int i = 1;i<=9;i++)
      {
        for(int j = 1;j<=9;j++)
        {
          cout<<mas[i][j];
          if(j == 3|| j == 6)
          cout<<' ';
        }
        cout<<endl;
        if(i%3 == 0)
        cout<<endl;
      }
    }



  return 0;
}
