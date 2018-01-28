#include<stdio.h>  int main()  { 
      int a[100];       int n,i,k,b,c;        
      while(scanf("%d",&n)!=EOF)       { 
         if(n==1) printf("1=1\n");          else{           b=n;           c=0; 
         for(i=0;n!=1;i++)          { 
         for(k=2;;k++)          { 
         if(n%k==0)          { 
             a[i]=k;              n=n/k;              c++;              break;   
         }          }          } 
         printf("%d=",b);          for(i=0;i<c;i++)          { 
         printf("%d",a[i]);          if(i<c-1) printf("*");          } 
         printf("\n");       }       } 
     return 0;  }
