#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define INF 0x3f3f3f3f
const double eps = 1e-6;
#define ll long long
#define clr(a,x) memset(a,x,sizeof(a))
char s[3][200];
int main()
{
  std::ios::sync_with_stdio(false);
  cin>>s[1];
  cin>>s[2];
  int len = strlen(s[1]);
  int num = 0;
  for(int i = 0;i<len;i++)
  {
    if(s[1][i]=='0' && s[2][i] == '0')
    {
      if(s[1][i+1]=='0')
      {
          s[1][i+1]='1';
          num++;
      }
      else
      if(s[2][i+1]=='0')
      {
          s[2][i+1]='1';
          num++;
      }
    }
    else if(s[1][i]=='0'||s[2][i]=='0')
    {
        if(s[1][i+1]=='0' && s[2][i+1]=='0')
        {
            num++;
            s[1][i+1]='1';
            s[2][i+1]='1';
        }
    }

  }
  cout<<num<<endl;
  return 0;
}
