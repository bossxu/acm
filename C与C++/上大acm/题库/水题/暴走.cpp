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
int find_out(int i,int *a)
{
    *a++;
    if ( f[i] != i ) f[i]=find(f[i]) ;
	return f[i];
}
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    n=n-1;
    while(n--)
    {
        scanf("%d%d",&a,&b)
    }


    return 0;
}
