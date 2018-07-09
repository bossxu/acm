#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
struct node
{
    int id;
    int cnt;
}a[30];
bool cmp(node x,node y)
{
    if(x.cnt==y.cnt)
        return x.id<y.id;
    return x.cnt<y.cnt;
}
char s[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int N,K;
        cin>>N>>K;
        for(int i=1;i<=26;i++)
            a[i].id=96+i;
        cin>>s;
        for(int i=0;i<N;i++)
        {
            a[s[i]-'a'+1].cnt++;
        }
        bool flag=false;
        ll ans = 0;
        int index = 26;
        for(int i=25;i>=1;i--)
        {
            if(K>=N-a[i].cnt-1)
            {
              if((a[i].id-a[index].id)*(2*a[i].cnt - 1 + min(K,N-a[i].cnt)) > 2*(a[index].cnt - a[i].cnt)*a[index].id)
              {
                index = i;
              }
                //cout<<ans<<endl;
            }
        }
        ans=1LL*N*(N-1)/2*a[index].id;
        sort(a+1,a+27,cmp);
        for(int i=1;i<=26;i++)
        {
          int item = 2;
          if(K<=0)
          break;
          int x=min(K,a[i].cnt);
          for(int j = 2;j<=26;j++)
          {
            if((a[j].id-a[item].id)*(2*a[j].cnt - 1 + x) > 2*(a[item].cnt - a[j].cnt)*a[item].id)
            {
              item = j;
            }
          }
            K-=x;
            a[i].cnt-=x;
            a[item].cnt+=x;
        }
        ll op = 0;
        for(int i=1;i<=26;i++)
        {
            op+=1LL*a[i].cnt*(a[i].cnt-1)/2*a[i].id;
        }
        //cout<<op<<endl;
        cout<<max(ans,op)<<endl;
    }
    return 0;
}
