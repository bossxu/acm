#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<cstdlib>

int n,m;

int main()
{
    cin>>n>>m;
    memset(tree,0,sizeof(tree));
    int a,b,c;
    for(int i = 1;i<=m;i++)
    {
      cin>>a>>b>>c;
      for(int i = a;i<=b;i++)
      {
        tree[i]+=c;
      }
    }
    for(int i = 1;i<n;i++)
    {
      cout<<tree[i]<<" ";
    }
   cout<<tree[n]<<endl;


}
