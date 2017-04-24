/*Wyrazy budowane są z liter a..z. Dwa wyrazy „ważą” tyle samo jeżeli: mają tę samą liczbę samogłosek oraz sumy kodów ascii liter z których są zbudowane są identyczne.

Na przykład „ula” -> 117+108+97=322 oraz „exe” -> 101+120+101=322.

Twoim zadaniem jest wczytanie dwóch wyrazów i oraz sprawdzenie czy z podzbioru liter zawartych w słowie można stworzyć wyraz ważący tyle samo co wyraz .*/

//two words to compare

#include <stdio.h>
#define SIZE 31

int lettersum(int*, int);
int number_vowels(int*, int);
int vowels_table(int*, int);
void combination_nonvowels(int);
void combination_vowels(int);
void combination_sum(void);

int word1[SIZE];
int word2[SIZE];
int word1_size;
int word2_size;
int word1_sum;
int word1_vowels_number;
int word2_vowels_number;
int word2_vowels[SIZE];
int word2_nonvowels[SIZE];
int word2_vowels_0_1[SIZE] = {0};
int word2_nonvowels_0_1[SIZE] = {0};
int result = 0;
int loop = 0;

int main()
{
	int k, i;
	char input[62];

	/*POBIERANIE DANYCH WEJSCIOWYCH I ICH ZAPIS W KODZIE ASCII*/

	fgets(input, 62, stdin);

	k = 0;
	while(input[k]!=' ')
	{
		word1[k] = input[k];
		k++;
		if(k==SIZE)
			break;
	}
	word1_size = k;

	i = k+1;
	k = 0;
	while(input[i]!='\0')
	{
		word2[k] = input[i];
		i++;
		k++;
		if(i==SIZE)
			break;
	}
	word2_size = k;

	word1_sum = lettersum(word1, word1_size);
	word1_vowels_number = number_vowels(word1, word1_size);
	word2_vowels_number = vowels_table(word2, word2_size);

	combination_nonvowels(word2_size-word2_vowels_number);

	if(result==1)
		printf("TAK");
	else
		printf("NIE");

	return 0;
}

void combination_nonvowels(int n)
{
	if(n==0)
	{
		combination_vowels(word2_vowels_number);
	}
	else
	{
		word2_nonvowels_0_1[n-1] = 0;
		combination_nonvowels(n-1);

		word2_nonvowels_0_1[n-1] = 1;
		combination_nonvowels(n-1);
	}
}

void combination_vowels(int n)
{
	if(n==0)
	{
		combination_sum();
	}
	else
	{
		word2_vowels_0_1[n-1] = 0;
		combination_vowels(n-1);

		word2_vowels_0_1[n-1] = 1;
		combination_vowels(n-1);
	}	
}

void combination_sum(void)
{
	int k;
	int sum_check = 0;
	int h = 0;
	for(k=0; k<word2_vowels_number; k++)
	{
		if(word2_vowels_0_1[k]==1)
		{
			sum_check = sum_check + word2_vowels[k];
			h++;
		}
	}

	for(k=0; k<(word2_size-word2_vowels_number); k++)
	{
		if(word2_nonvowels_0_1[k]==1)
			{
				sum_check = sum_check + word2_nonvowels[k];
			}
	}
	if((sum_check==word1_sum)&&(h==word1_vowels_number))
		result = 1;
	sum_check = 0;
	h = 0;
}

int vowels_table(int* word, int size)
{
	int number = 0;
	int i = 0;
	int k = 0;

	while(k<size)
	{
		if( (word[k]=='a')||(word[k]=='e')||(word[k]=='i')||(word[k]=='o')||(word[k]=='u') )
			{
				word2_vowels[number] = word[k];
				number++;
			}
		else
			{
				word2_nonvowels[i] = word[k];
				i++;
			}
		k++;
	}

	return number;
}

int lettersum(int* word, int size)
{
	int k = 0;
	int sum = 0;

	while(k<size)
	{
		sum = sum + word[k];
		k++;
	}

	return sum;
}

int number_vowels(int* word, int size)
{
	int number = 0;
	int k = 0;

	while(k<size)
	{
		if( (word[k]=='a')||(word[k]=='e')||(word[k]=='i')||(word[k]=='o')||(word[k]=='u') )
			{
				number++;
			}
		k++;
	}

	return number;
}
