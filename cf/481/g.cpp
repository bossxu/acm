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
struct node
{
  int qst,end,d;
  int index;
}exam[200];
int n,m;
int cmp(node a, node b)
{
  return a.end<b.end;
}
int shu[200];
int main()
{
  std::ios::sync_with_stdio(false);
  while(cin>>n>>m)
  {
    bool flag = 0;
    clr(shu,0);
    for(int i = 1;i<=m;i++)
    {
      cin>>exam[i].qst>>exam[i].end>>exam[i].d;
      exam[i].index = i;
      if(exam[i].d > exam[i].end - exam[i].qst || shu[exam[i].end])
        flag = 1;
      shu[exam[i].end] = m+1;
    }
    sort(exam+1,exam+m+1,cmp);
    if(flag)
    {
      cout<<-1<<endl;
    }
    else
    {
      //cout<<"ok"<<endl;
      for(int i = 1;i<=n;i++)
      {
        int j;
        int item = 0;
        if(shu[i])
        {
          for(j = 1;j<=m;j++)
          {
            if(exam[j].d>0 && i>=exam[j].end){ flag = 1;}
            //cout<<exam[j].d<<" "<<exam[j].end<<endl;
          }
          continue;
        }
        for(j = 1;j<=m;j++)
        {
          if(exam[j].d>0 && i>=exam[j].end) flag = 1;
          if(exam[j].d>=1 && exam[j].qst<=i)
          {
            item = 1;
            break;
          }
        }
        if(item)
        { shu[i] = exam[j].index;
          exam[j].d--;}
        //cout<<i<<" "<<flag<<endl;
      }
      if(flag)
      {
        cout<<-1<<endl;
      }
      else
      {
        for(int i = 1;i<n;i++)
          cout<<shu[i]<<" ";
        cout<<shu[n]<<endl;
      }
    }

  }
  return 0;
}
