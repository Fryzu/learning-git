//First line input question number
//Second line - questions
//PRIMES

#include <stdio.h>
#define MAX 1000001

void sito(void);
void check(int);
unsigned char primes[MAX];

int main()
{
    sito();

    int z,x;
    scanf("%i",&z);

    while(z>0)
    {
        scanf("%i",&x);
        check(x);

        --z;
    }

    return 0;
}

void sito()
{
    int k = 2;
    int i;
    primes[0] = 0;
    primes[1] = 0;

    for (k;k<MAX;k++)
    {
        primes[k] = 1;
    }

    k = 2;
    while(k<MAX)
    {
        if(primes[k]==1)
        {
            for(i=2;(k*i)<MAX;i++)
            {
                primes[k*i] = 0;
            }
        }

        k++;
    }
}

void check(int a_in)
{
    if(primes[a_in]==1)
        printf("TAK\n");
    else
        printf("NIE\n");
}

