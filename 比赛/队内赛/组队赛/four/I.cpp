#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    while(cin>>N>>M)
    {
      if(N==1)
      {
        if(M%2==0)
          cout<<2<<endl;
          else
          cout<<1<<endl;
          continue;
      }
      if(M==1)
      {
        if(N%2==0)
        cout<<0<<endl;
        else
        cout<<1<<endl;
        continue;
      }
      if(N%2==1&&M==2)
      {
          cout<<0<<endl;
          continue;
      }
      if(N%2==1&&M%2==0)
      {
        cout<<2<<endl;
        continue;
      }
      if(N%2==1&&M%2==1)
      {
        cout<<1<<endl;
        continue;
      }
      cout<<0<<endl;
    }
    return 0;
}
