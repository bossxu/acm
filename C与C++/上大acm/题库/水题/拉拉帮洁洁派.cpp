#include<cstdio>
#include<iostream>
#define Ma 100005
int f[Ma];
using namespace std;
int find( int  i ) {//目的是查找根节点，
	if ( f[i] != i ) f[i]=find(f[i]) ;
	return f[i];
}
void unin( int a, int b ) {//目的是把两个根节点结合起来
	int ta=find(a);
	int tb=find(b);
	if(ta!=tb) f[ta]=f[tb];
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) f[i]=i;
    while(m--)
    {
        int a,b,t;
        while(scanf("%d%d%d",&t,&a,&b)==3)
        {
            if(t==1)
            {
                unin(a,b);
               //把关系存进去
            }
            else if(t==2)
            {
                //把关系读出来
                int i=find(a);
                int j=find(b);
                if(i==j) printf("Yes\n");
                else printf("No\n");
            }
        }
    }
    return 0;
}

