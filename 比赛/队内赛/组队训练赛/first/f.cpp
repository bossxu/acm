#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int len[maxn*2],link[maxn*2],go[maxn*2][26];
int sz,last;
char s[maxn];
int a[maxn*2],c[maxn*2];
int dp[maxn*2];
int sum[maxn*2];
int id;
int cnt[maxn*2];
int pp[maxn*2];
int ans;
int N;
char tmp[1005];
void sam_init()
{
    memset(pp,0,sizeof(pp));
    memset(go,0,sizeof(go));
    memset(cnt,0,sizeof(cnt));
    sz=last=0;
    len[0]=0;
    link[0]=-1;
    sz++;
}
void sam_extend(int c)
{
    int cur=sz++;
    len[cur]=len[last]+1;
    int p;
    for(p=last;p!=-1&&!go[p][c];p=link[p])
        go[p][c]=cur;
    if(p==-1)
        link[cur]=0;
    else
    {
        int q=go[p][c];
        if(len[p]+1==len[q])
            link[cur]=q;
        else
        {
            int clone=sz++;
            len[clone]=len[p]+1;
            link[clone]=link[q];
            cnt[clone]=cnt[q];
            memcpy(go[clone],go[q],sizeof(go[clone]));
            for(;p!=-1&&go[p][c]==q;p=link[p])
                go[p][c]=clone;
            link[cur]=link[q]=clone;
        }
    }
    last=cur;
    for(;cur!=0;cur=link[cur])
    {
        if(pp[cur]!=id)
        {
            cnt[cur]++;
            pp[cur]=id;
        }

    }
}
void dfs(int u,int d)
{
    if(len[u]<d||d>ans)
        return ;
    if(d==ans&&cnt[u]>N)
    {
        tmp[d]='\0';
        puts(tmp);
        return ;
    }
    for(int i=0;i<26;i++)
    {
        if(go[u][i])
        {
            int v=go[u][i];
            tmp[d]=i+'a';
            dfs(v,d+1);
        }
    }
}
int main()
{
    while(scanf("%d",&N)!=EOF&&N)
    {
        sam_init();
        for(int i=1;i<=N;i++)
        {
            id=i;
            last=0;
            scanf("%s",s);
            int n=strlen(s);
            for(int j=0;j<n;j++)
                sam_extend(s[j]-'a');
        }
        N/=2;
        ans=0;
        for(int i=1;i<sz;i++)
        {
            //cout<<cnt[i]<<endl;
            if(cnt[i]>N)
                ans=max(ans,len[i]);
        }
        if(ans==0)
        {
            printf("?\n");
        }
        else
        {
            dfs(0,0);
        }
        printf("\n");
    }
    return 0;
}
