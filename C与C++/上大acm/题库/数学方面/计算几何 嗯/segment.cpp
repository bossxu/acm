#include <iostream>  
#include <string.h>  
#include <algorithm>
using namespace std;  
struct Dian  
{  
    int x,y;  
};  
struct Line  
{  
    Dian a,b;  
}line[5001];  
int n,m,total[5001];  
int chaji(Dian p0,Dian p1,Dian p2) 
{  
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);  
}  
  
void judge(Dian d)  
{  
    int i;  
    for(i=0;i<n;++i)  
    {  
        if(chaji(line[i].b,d,line[i].a)>0)  continue;  
        else    {++total[i];return;}  
    }  
    ++total[n];  
    return;  
}  
int cmp(Line k1,Line k2 )
{
    if(k1.a.x<k2.a.x)
    return 1;
    return 0;
}
int main()  
{  
    int i;  
    Dian left_up,right_low,temp; 
    int F[5001]; 
  
    while(cin>>n && n)  
    {  
        cin>>m>>left_up.x>>left_up.y>>right_low.x>>right_low.y;  
        memset(total,0,sizeof(total));  

  
        for(i=0;i<n;++i)  
        {  
            cin>>line[i].a.x>>line[i].b.x;  
            line[i].a.y=left_up.y;  
            line[i].b.y=right_low.y;  
        }  
        sort(line,line+n,cmp);
        for(i=0;i<m;++i)  
        {  
            cin>>temp.x>>temp.y;  
            judge(temp);  
        }  
        int z=0;
        memset(F,0,sizeof(F));
       for(int i=0;i<=n;i++)
       {
          // printf("  %d",total[i]);
          F[total[i]]++;
          z = max(z,total[i]);
       }
       printf("Box\n");  
       for(int i=1;i<=z;i++)
       {
           if(F[i]>0)
           printf("%d: %d\n",i,F[i]);
       }
    }  
    return 0;  
}  
