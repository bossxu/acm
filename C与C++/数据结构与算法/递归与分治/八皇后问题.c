#include<stdio.h>

int count=0;//计数用的
//row：行的意思；n:列的意思；chess：棋盘
int Pandanger(int row, int j,int (*chess)[8])//有问题
{

    //判定一个列是否有皇后
    //判定斜线是否有皇后
    //斜线通过左上方，左下方，右下方，右上方分解问题

   int i,k,item=1;
   for(i=0;i<8;i++)//判断列方向
    {
        if(*(*(chess+i)+j)!=0)
        {
           return 0;
        }
    }
    for(i=row,k=j;i>=0&&k>=0;i--,k--)//左上方
    {
        if(*(*(chess+i)+k)!=0)
        {
          return 0;
        }
    }
    for(i=row,k=j;i<8&&k<8;i++,k++)//右下方
    {
        if(*(*(chess+i)+k)!=0)
        {
          return 0;
        }
    }
    for(i=row,k=j;i>=0&&k<8;i--,k++)//右上方
    {
        if(*(*(chess+i)+k)!=0)
        {
           return 0;
        }
    }
    for(i=row,k=j;i<8&&k>=0;i++,k--)//左下方
    {
        if(*(*(chess+i)+k)!=0)
        {
            return 0;
        }
    }
    return 1;
}

void EightQueen(int row,int  n, int (*chess)[8])//皇后的主程序
{
  int i,j,chess2[8][8];
  for(i=0;i<8;i++)
  {
      for(j=0;j<8;j++)
      {
           chess2[i][j]=chess[i][j];//新棋盘的初始化
      }
  }
  if(row==8)
  {//把棋盘输出
  printf("第%d种:\n",count+1);
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                printf("%d ",*(*(chess2+i)+j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
  }
  else
  {
      for(j=0;j<n;j++)//完美解决所有情况，第一行的8中情况
      {
          if(Pandanger(row,j,chess))//判断位置是否危险
          {
              for(i=0;i<8;i++)
              {
                  *(*(chess2+row)+i) =0;//列的初始化
              }
               *(*(chess2+row)+j) =1;//只有这一列的，满足条件的才会放上一个女皇
               EightQueen(row +1,n,chess2);//我认为的核心
          }
      }
  }

}
int main()
{
    int i,j,chess[8][8];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            chess[i][j]=0;//一开始为空的棋盘，初始化
        }
    }
         EightQueen(0,8,chess);
         printf("总共有%d种解决方案",count);


    return 0;
}
