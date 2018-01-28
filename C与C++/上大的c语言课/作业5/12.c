#include<stdio.h>
int main()
{
    char zifu[80];
    int i=0,j=0,k=0,sum=0;
    while((zifu[i]=getchar())!='\n')
    {
        i++;
    }

    while(j<i)
    {
        if(zifu[j]==' ')
        {
            j++;
            continue;
            }
        else
        {
            if(zifu[j]<='z'&&zifu[j]>='a')
                {zifu[j]=zifu[j]-32;}
            sum=sum+1;
            do{

                j++;

            }while(zifu[j]!=' '&&j<i);
        }
    }

    printf("%d\n",sum);
  for(k=0;k<i;k++)
  {
      printf("%c",zifu[k]);
  }

    return 0;
}
