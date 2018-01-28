#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct stud
{
     int st,en;

}node[105];
int cmp(stud a,stud b)
{
    if(a.en<b.en) return 1;
    else if(a.en==b.en)
    {
        if(a.st<b.st ) return 1;
    }
     return 0;
}
int main()
{
    int T,i,j,k;
    while(cin>>T && T)
    {
        int m=1,ma=0;
        for(i=0;i<T;i++)
        {
            cin>>node[i].st>>node[i].en;
        }
        sort(node,node+T,cmp);
        i =0;
        while(i<T)
        {
            for(j=i+1;node[j].st<node[i].en &&  j<T;j++);
            i=j;
            if(j!=T) m++;
        }
        printf("%d\n",m);
    }
}
