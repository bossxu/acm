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

string a = "jessie";
string s;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>s;
    int len = s.length();
    for(int i = 0;i<len;i++)
    {
      if(s[i]>='A' && s[i]<='Z')
      s[i] = s[i]-'A'+'a';
    }
    if(s=="jessie")
      cout<<"Good guy!"<<endl;
    else
      cout<<"Dare you say that again?"<<endl;
  }
  return 0;
}
