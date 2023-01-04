#include<stdio.h>
#include<stdlib.h>


unsigned long long int Pow_(unsigned long long int X, int a);
int findBinDigits(unsigned long long int s);
int D2B()
{
	int i, j, k;
	unsigned long long int s = 0;
	unsigned int Bin[64] = { 0 };
	unsigned int temp[64] = { 0 };


	printf("請輸入欲轉換的數(十進制):");
	scanf("%lld", &s);
	printf("十進制%lld的二進制為",s);

	i = findBinDigits(s);//i為二進制的位數

	for (k = 0; k < i; k++)
	{
		temp[k] = s % 2;
		s = s / 2;
	}
	for (k = 0; k < 64; k++)
		Bin[63 - k] = temp[k];
	for (k = 64 - i; k < 64; k++)
		printf("%d", Bin[k]);
	printf("(%d位數)\n\n", i);


	//system("pause");
	return 0;
}


unsigned long long int Pow_(unsigned long long int X, int a)
{
	if (a == 0)
		return 1;
	else
		return X * Pow_(X, a - 1);
}



int findBinDigits(unsigned long long int s)
{
	int i;
	for (i = 0; i < 64; i++)//i為二進制的數
	{
		if (s == Pow_(2, i))
			return i + 1;
		else if (s < Pow_(2, i))
			return i;
	}
}