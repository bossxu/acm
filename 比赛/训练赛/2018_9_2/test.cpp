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
int f[ 15000];
void getfill(string s)
{
    memset(f,0,sizeof(f));  //根据其前一个字母得到
    for(int i=1;i<s.size();i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}
char s[1000];
int main()
{
  ios_close;
  while(cin>>s)
  {
    getfill(s);
    for(int i = 0;i<strlen(s);i++)
    {
      cout<<f[i+1];
    }
    cout<<endl;
  }
  return 0;
}
