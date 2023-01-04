#include<stdio.h>
#include<stdlib.h>

const int bin[2] = { 48, 49 };//48=0 49=1
unsigned long long int BinToDec(int* B, char* t, int* j);
int B2D()
{
	int Bin[64] = { 0 };
	char temp[64];
	int i=0, j;
	unsigned long long int sum;

	printf("輸入二進制(至多64位數):");
	scanf("%s", temp);
		
	sum = BinToDec(Bin, temp, &i);
	
	for (j = 64 - i; j < 64; j++)
		printf("%d", Bin[j]);

	printf("(%d位數)的十進制為%lld\n\n", i, sum);
	//system("pause");
	return 0;
}

unsigned long long int Pow__(unsigned long long int X, int a)
{
	if (a == 0)
		return 1;
	else
		return X * Pow__(X, a - 1);
}

unsigned long long int BinToDec(int* B, char* t, int* i)
{
	int j,k;
	unsigned long long int sum = 0;

	for (j = 0; *(t + j) != '\0'; j++)
		*i = j;
	*i = *i + 1;

	for (j = 64 - *i, k = 0; j < 64 || k < 64; j++, k++)//Bin為01的形式
		if (*(t + k) == 48)
			*(B + j) = 0;
		else if (*(t + k) == 49)
			*(B + j) = 1;

	for (j = 63; j >= 0; j--)
			if(*(B + j) == 1)
				sum = sum + Pow__(2, 63 - j);
	return sum;
}