#include<bits/stdc++.h>
using namespace std;
const int maxnode=1e5*30;
const int sigma_size=26;
int ch[maxnode][sigma_size];
int val[maxnode];
int sz;
void clear()
{
  sz=1;
  memset(ch[0],0,sizeof(ch[0]));
  memset(val,0,sizeof(val));
}
int idx(char c)
{
  return c-'a';
}
void Insert(const char *s)
{
  //bool flag=false;
  int cnt=0;
  int u=0,n=strlen(s);
  for(int i=0;i<n;i++)
  {
    int c=idx(s[i]);
    if(!ch[u][c])
    {
      memset(ch[sz],0,sizeof(ch[sz]));
      val[sz]=0;
      ch[u][c]=sz++;
    }
    else
    {
      cnt++;
    }
  }
  val[u]++;
}
char tmp=
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N,M;
  while(cin>>N>>M)
  {

  }
  return 0;
}
