#include<stdio.h>
#include<string.h>
int main()
{
    char strr[100],strs[100];
    int n,i,j;
    while(scanf("%s",strr)!=EOF){
            n=strlen(strr);
            //printf("%d\n", n);
            for(i=0;i<n;i++)
            {
                j=n-1-i;
                strs[i]=strr[j];
            }
            printf("%s\n",strs);
    }
    return 0;
}
