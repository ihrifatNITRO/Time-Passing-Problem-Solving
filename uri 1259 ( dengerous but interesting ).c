#include<stdio.h>
int main()
{
    int n,i,j,k,q,w,even=0,odd=0,jor[even],bijor[odd];
    scanf("%d",&n);
    int a;
    i=0;
    while(i<n)
    {
        scanf("%d",&a);
        if(a%2 == 0)
        {
            jor[even] = a;
            even++;
        }
        else
        {
            bijor[odd] = a;
            odd++;
        }
        i++;
    }
    j=0;
    while(j<even)
    {
        int min = jor[j];
        for(k=j+1;k<even;k++){
            if(jor[j] > jor[k])
            {
                int temp = jor[j];
                jor[j] = jor[k];
                jor[k] = temp;
            }
        }
        j++;
    }
    k=0;
    while(k<even)
    {
        printf("%d\n",jor[k]);
        k++;
    }
    q=0;
    while(q<odd)
    {
        int min = bijor[q];
        for(w=q+1;w<odd;w++){
            if(bijor[q] < bijor[w])
            {
                int temp = bijor[q];
                bijor[q] = bijor[w];
                bijor[w] = temp;
            }
        }
        q++;
    }
    q=0;
    while(q<odd)
    {
        printf("%d\n",bijor[q]);
        q++;
    }
    return 0;
}
