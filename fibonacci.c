#include <stdio.h>

long long int fibonacci(int n, long long int a, long long int b)
{
	if(n==0)
		return 0;
	if(n<=2)
		return b;
		
	return fibonacci(n-1, b, a+b);
}

int main()
{
	int n;
	scanf("%i", &n);
	printf("%lld\n", fibonacci(n, 1, 1));

	return 0;
}
