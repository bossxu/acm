#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<string,ll>dp;
string s;
set<string>op[2];
int num[(1<<19) + 6];
char shu[3][(1<<18)+6];
int main()
{
    int n;
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n)
    {
        dp.clear();
        op[0].clear();op[1].clear();
        cin>>s;
        op[0].insert(s);
        dp[s] = 1;
        int len = 1<<n;
        int flag = 0;
        for(int i = 1;i<=n;i++)
        {
            int next = flag^1;
            for(set<string>::iterator u = op[flag].begin();u!=op[flag].end();u++)
            {
                int a1 = 0,a2 = 0,a3 = 0;
                for(int j = 1;j<=len;j++)
                {
                    num[j] = (*u)[j-1] - '0';
                    if(j%2 == 0)
                    {
                        shu[0][j/2 -1] = (num[j]^num[j-1])+'0';
                        shu[1][j/2 -1] = (num[j]|num[j-1])+'0';
                        shu[2][j/2 -1] = (num[j]&num[j-1])+'0';
                        if(shu[0][j/2-1] == '1') a1 = 1;
                        if(shu[1][j/2-1] == '1') a2 = 1;
                        if(shu[2][j/2-1] == '1') a3 = 1;
                    }
                }
                    string a,b,c;
                    a = shu[0],b = shu[1],c = shu[2];
                    a.resize(len/2),b.resize(len/2),c.resize(len/2);
                    //cout<<a<<" "<<b<<" "<<c<<endl;
                    if(a1) op[next].insert(a);
                    if(a2) op[next].insert(b);
                    if(a3) op[next].insert(c);
                    dp[a] += dp[*u];
                    dp[b] += dp[*u];
                    dp[c] += dp[*u];
            }
            len>>=1;
            op[flag].clear();
            flag = next;
        }
        string op1 = "1";
        cout<<dp[op1]<<endl;
    }

}
