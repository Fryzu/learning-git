//Bubble sort
//First line number of input numbers
//Second line input data

#include <stdio.h>

void swap(int,int);
void bubble_sort(int);
int table[1001];

int main()
{
    int size_table;
    scanf("%i",&size_table);

    int k;
    for(k=0; k<size_table; k++)
        scanf("%i",&table[k]);

    bubble_sort(size_table);

    for(k=0; k<size_table; k++)
        printf("%i ",table[k]);

    return 0;
}

void swap(int a, int b)
{
    table[a] = table[a]+table[b];
    table[b] = table[a]-table[b];
    table[a] = table[a]-table[b];
}

void bubble_sort(int size_table)
{
    int a = size_table;
    int b;

    for(a; a>1; --a)
    {
        for(b=1; b<a; b++)
        {
            if(table[b-1]>table[b])
                swap(b-1,b);
        }
    }
}

