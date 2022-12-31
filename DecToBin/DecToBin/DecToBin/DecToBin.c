#include<stdio.h>
#include<stdlib.h>



unsigned long long int Pow(unsigned long long int X, int a);
int findBinDigits(unsigned long long int s);
int main()
{
	int i, j, k;
	unsigned long long int s = 0;
	unsigned int Bin[64] = { 0 };
	unsigned int temp[64] = { 0 };


	printf("叫块饼锣传计(秈):");
	scanf("%lld", &s);
	printf("秈%lld秈",s);

	i = findBinDigits(s);//i秈计

	for (k = 0; k < i; k++)
	{
		temp[k] = s % 2;
		s = s / 2;
	}
	for (k = 0; k < 64; k++)
		Bin[63 - k] = temp[k];
	for (k = 64 - i; k < 64; k++)
		printf("%d", Bin[k]);
	printf("(%d计)\n\n", i);


	system("pause");
	return 0;
}

unsigned long long int Pow(unsigned long long int X, int a)
{
	if (a == 0)
		return 1;
	else
		return X * Pow(X, a - 1);
}



int findBinDigits(unsigned long long int s)
{
	int i;
	for (i = 0; i < 64; i++)//i秈计
	{
		if (s == Pow(2, i))
			return i + 1;
		else if (s < Pow(2, i))
			return i;
	}
}