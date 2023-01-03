#include<stdio.h>
#include<stdlib.h>


const int table[16] = { 48,49,50,51,52,53,54,55,56,57,//0~9
				65,66,67,68,69,70 };//A~F

long long int HexToDec(char *in, int *Dec, int j);
unsigned long long int Pow(unsigned long long int X, int a);
int findBinDigits(unsigned long long int s);
int main()
{
	int i, j, k;
	unsigned long long int sum = 0;
	char in[17] = { 0 };
	int Hec[17] = { 0 };
	unsigned int Bin[64] = { 0 };
	unsigned int temp[64] = { 0 };


	printf("�п�J���ഫ����(�ܦh16���A~F�j�g):");
	scanf("%s", &in);

	for (j = 0; in[j] != '\0'; j++);//j���
	printf("0X%s(%d���)���G�i�\n", in, j);

	sum = HexToDec(in, Hec, j);

	i = findBinDigits(sum);//i���G�i����

	for (k = 0; k < i; k++)
	{
		temp[k] = sum % 2;
		sum = sum / 2;
	}
	for (k = 0; k < 64; k++)
		Bin[63 - k] = temp[k];
	for (k = 64 - i; k < 64; k++)
		printf("%d", Bin[k]);
	printf("(%d���)\n\n", i);


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

long long int HexToDec(char *in, int *Dec, int j)
{
	long long int s = 0;
	int i, f;
	for (i = 0; i <= j; i++)
	{
		for (f = 0; f < 16; f++)
			if (*(in + i) == table[f])
				*(Dec + i) = f;
	}

	for (i = 0; i < j; i++)
		s = s + *(Dec + i) * Pow(16, j - i - 1);

	return s;
}

int findBinDigits(unsigned long long int s)
{
	int i;
	for (i = 0; i < 64; i++)//i���G�i����
	{
		if (s == Pow(2, i))
			return i + 1;
		else if (s < Pow(2, i))
			return i;
	}
}