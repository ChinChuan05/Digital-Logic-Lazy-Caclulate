#include<stdio.h>
#include<stdlib.h>

const int bin[2] = { 48, 49 };//48=0 49=1
unsigned long long int Pow(unsigned long long int X, int a);
unsigned long long int BinToDec(int* B, char* t, int* j);
int main()
{
	int Bin[64] = { 0 };
	char temp[64];
	int i=0, j;
	unsigned long long int sum;

	printf("輸入二進制(至多64位數):");
	scanf("%s", temp);
		
	printf("A%s\n", temp);
	for (j = 0; j < 64; j++)
		printf("%d", Bin[j]);
	printf("\n\n");

	sum = BinToDec(Bin, temp, &i);

	printf("\n\ni= %d B%s\n\n",i, temp);

	for (j = i+1; j < 64; j++)
		printf("%d", Bin[j]);
	printf("(%d位數)的十進制為%lld\n\n", 63 - i, sum);
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

unsigned long long int BinToDec(int* B, char* t, int* i)
{
	int j, judge = 0;
	int regit[64] = { 0 };
	unsigned long long int sum = 0;

	for (j = 0; j < 64; j++)//Bin為01的形式
		if (*(t + j) == 48)
			regit[j] = 0;
		else if(*(t + j) == 49)
			regit[j] = 1;

	for (j = 63; j < 0; j--)
		if (judge == 0)
		{
			if (*(B + j) == 1)
			{
				judge = 1;
				*(i) = j;
			}
		}
		else if (judge == 0)
		{
			if(*(B + j) == 1)
				sum = sum + Pow(2, 63 - j);
		}
	return sum;
}