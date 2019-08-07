#include<stdio.h>
#include<math.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n) != EOF){
    int i,j,k,l,sum,flag = 0;
    for(i = m;i <= n;i++)
    {  j = i / 100;
       k = (i -j * 100) / 10;
       l = i % 10;
       sum = pow(j,3) + pow(k,3) + pow(l,3);
       if(sum == i)
       {
           if(flag == 0){printf("%d",i);flag++;}
           else {printf(" %d",i);flag++;}
       }
    }
    if(flag == 0)
        printf("no\n");
    else
        printf("\n");
    }
    return 0;
}
