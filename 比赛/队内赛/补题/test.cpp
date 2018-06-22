#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+7;
bool vis[maxn];
int prime[maxn],mu[maxn];
int cnt;

void Init(){
    int N=maxn;
    memset(prime,0,sizeof(prime));
    memset(mu,0,sizeof(mu));
    memset(vis,0,sizeof(vis));
    mu[1] = 1;
    cnt = 0;
    for(int i=2; i<N; i++){
        if(!vis[i]){
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j=0; j<cnt&&i*prime[j]<N; j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j]) mu[i*prime[j]] = -mu[i];
            else{
                mu[i*prime[j]] = 0;
                break;
            }
        }
    }
}

void getMu(){
    int N=maxn;
	for(int i=1;i<N;++i){
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for(int j=2*i;j<N;j+=i)
			mu[j]+=delta;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    int a,b,c,d,k;
    int T,Case=0;
    Init();
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d>>k;
        cout<<"Case "<<++Case<<": ";
        if(k==0){
            cout<<"0"<<endl;
            continue;
        }
        b/=k,d/=k;
        long long ans1=0,ans2=0;
        for(int i=1;i<=min(b,d);i++){
            ans1+=(long long)mu[i]*(b/i)*(d/i);
        }
        for(int i=1;i<=min(b,d);i++){
            ans2+=(long long)mu[i]*(min(b,d)/i)*(min(b,d)/i);
        }
        cout<<ans1-ans2/2<<endl;
    }
    return 0;
}
