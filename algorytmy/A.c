/*Greatest common dividor NWD
  and least common multuple NWW*/

#include <stdio.h>

int nwd(int,int);

int main()
{
    int a,b,c,x;
    long long int y;
    scanf("%i",&c);

    while(c>0)
    {
        scanf("%i %i",&a,&b);
        x = nwd(a,b);
        y = ((long long int )a*(long long int)b)/(long long int)x;
        printf("%i %lli\n",x,y);

        --c;
    }

    return 0;
}

int nwd(int a, int b)
{
    int i;
    while(b!=0)
    {
        i = b;
        b = a%b;
        a = i;
    }

    return a;
}

