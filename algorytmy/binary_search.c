
//First line number of input numbers and number of questions
//Second line questions

#include <stdio.h>

int bin_search(int, int[], int);

int tab[1000000] = {0};

int main()
{
    int n,k,search;
    scanf("%i %i",&n,&k);

    int i = 0;
    for(i; i<n; i++)
    {
        scanf("%i",&tab[i]);
    }

    i = 0;
    for(i; i<k; i++)
    {
        scanf("%i",&search);
        printf("%i ",bin_search(search,tab,n));
    }
    return 0;
}

int bin_search(int search, int tab[], int n)
{
    int left = 0;
    int right = n-1;
    long int center;
    int k;

    while(left<right)
    {
        center = left+(right-left)/2;

        if(tab[center]==search)
        {
            k = center;
            while(tab[center-1]==tab[center])
            {
                center--;
            }

            ++center;
            return center;
        }
        else
        {
            if(tab[center]<search)
            {
                left = center + 1;
            }
            else
            {
                right = center;
            }
        }
    }
    if(tab[right]==search)
    {
        right++;
        return right;
    }

    return -1;
}

