#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int gcd(int a,int b)
{
     return a%b==0?b:gcd(b,a%b);
}
int main()
{
  int N,M;
  while(cin>>M>>N)
  {
    if(M==-1 && N==-1)
    {
        break;
    }
    if(gcd(M,N)==1) printf("YES\n");
    else printf("POOR Haha\n");
  }

    return 0;
}