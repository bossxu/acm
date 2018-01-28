#include <iostream>  
#include <cstdio>  
#define MAX 400+5  
#define MAXK 500+5  
#define MOD 1000007  
using namespace std;  
  
int T,N,M,K,Case=0;  
int C[MAX][MAXK];  
  
int main()  
{  
    cin>>T;  
    C[0][0]=1;//注意边界！  
    for(int i=1;i<MAX;i++){  
        C[i][0]=C[i][i]=1;  
        for(int j=1;j<i;++j){  
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;  
        }  
    }  
  
    while(T--){  
        cin>>M>>N>>K;  
  
        int ans=0;  
        for(int S=0;S<16;++S){  
            int b=0,r=M,c=N;  
            if(S&1){b++,r--;}  
            if(S&2){b++,r--;}  
            if(S&4){b++,c--;}  
            if(S&8){b++,c--;}  
  
            if(b%2){ans=(ans+MOD-C[r*c][K])%MOD;}  
            else{ans=(ans+C[r*c][K])%MOD;}  
        }  
        cout<<"Case "<<++Case<<": "<<ans<<endl;  
    }  
    return 0;  
}