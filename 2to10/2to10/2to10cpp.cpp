#include<stdio.h>
#include<stdlib.h>

const int bin[2] = {48, 49};//48=0 49=1
unsigned long long int Pow(unsigned long long int X, int a);
void invert(int* B,char* t);

int main()
{
	int Bin[64] = { 0 };
	char temp[64] = { 0 };
	unsigned long long int Dec;

	printf("輸入二進制(至多64位數):");
	scanf("%s",temp);
	invert(Bin, temp);

		
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

void invert(int* B,char* t)
{
	int i;
	for (i = 0; i < 64; i++)
		*(t + i) = *(B + 63 - i);
}