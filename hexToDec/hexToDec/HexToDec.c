#include<stdio.h>
#include<stdlib.h>


const int table[16] = { 48,49,50,51,52,53,54,55,56,57,//0~9
				65,66,67,68,69,70 };//A~F

long long int HexToDec(char *in, int *Dec,int j);
int Pow(int X,int a);
int main()
{
	//16�i��%X 10�i��%d 8�i��%o 2�i��10->2
	//16��10
	int i, j;
	unsigned long long int sum=0;
	char in[17] = { 0 };
	int Dec[17] = { 0 };

	
	printf("�п�J���ഫ����(�ܦh16���A~F�j�g):");
	scanf("%s", &in);

	for (j = 0; in[j] != '\0'; j++);//j���
	printf("%s(%d���)���Q�i�\n",in,j);

	sum = HexToDec(in, Dec,j);
	
	printf("\n\n%lld",sum);
	system("pause");
	return 0;
}

int Pow(int X, int a)
{
	if (a == 0)
		return 1;
	else
		return X * Pow(X, a - 1);
}

long long int HexToDec(char *in, int *Dec,int j)
{
	long long int s = 0;
	int i,f;
	for (i = 0; i <= j; i++)
	{
		for (f = 0; f < 16; f++)
			if (*(in + i) == table[f])
				*(Dec + i) = f;
	}

	for (i = 0; i < j; i++)
		s = s + *(Dec+i) * Pow(16, j - i - 1);

	return s;
}