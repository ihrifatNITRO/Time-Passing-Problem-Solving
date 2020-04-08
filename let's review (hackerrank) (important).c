#include <stdio.h>
#include <stdlib.h>

int main() {

   int t,k=1;
    scanf("%d",&t);
    while(k <= t)
        {
        char a[10000];
        scanf("%s",a);
        int i;

        i=0;
        while(a[i]!='\0')
        {
            if(i%2==0)
            printf("%c",a[i]);
            i++;
        }
        printf(" ");

        i=0;
        while(a[i]!='\0')
        {
            if(i%2!=0)
            printf("%c",a[i]);
            i++;
        }

        k++;

        printf("\n");
    }
    return 0;
}

