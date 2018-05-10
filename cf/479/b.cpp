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
#define ll unsigned long long
#define clr(a,x) memset(a,x,sizeof(a))
char s[105];
int shu[10000];
int main()
{
  int n;
  while(cin>>n)
  {
    clr(shu,0);
    cin>>s;
    int item = 0;
    for(int i = 0;i<n-1;i++)
    {
      int c = s[i]-'A';
      c*=100;
      c+=s[i+1]-'A';
      shu[c]++;
      if(shu[c]>shu[item]) item = c;
    }
    printf("%c%c\n",item/100+'A',item%100+'A');
  }
  return 0;
}
