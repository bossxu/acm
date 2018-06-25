#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[5][105];
int main()
{
    for(int i=1;i<=2;i++)
        cin>>s[i];
    int n=strlen(s[1]);
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[1][i]=='0'&&s[1][i+1]=='0')
        {
            if(s[2][i]=='0')
            {
                ans++;
                s[2][i]='X';
                s[1][i]='X';
                s[1][i+1]='X';
                continue;
            }
            if(s[2][i+1]=='0')
            {
                ans++;
                s[2][i+1]='X';
                s[1][i]='X';
                s[1][i+1]='X';
                continue;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(s[2][i]=='0'&&s[2][i+1]=='0')
        {
            if(s[1][i]=='0')
            {
                ans++;
                s[1][i]='X';
                s[2][i]='X';
                s[2][i+1]='X';
                continue;
            }
            if(s[1][i+1]=='0')
            {
                ans++;
                s[1][i+1]='X';
                s[2][i]='X';
                s[2][i+1]='X';
                continue;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
