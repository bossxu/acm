#include<stdio.h>
int countdight(int number, int dight);
int main()
{
    int number;
    printf("Enter an integer: ");scanf("%d",&number);
    printf("Number of digit 2: %d",countdight(number,2));




    return 0;
}
int countdight(int number, int dight)
{
    int item,num=0;
    while(number!=0)
    {
       item=number%10;if(item==dight) num++;
       number/=10;
    }



    return num;
}
