#include<stdio.h>
#include<stdlib.h>

const int table_[16] = { 48,49,50,51,52,53,54,55,56,57,//0~9
				65,66,67,68,69,70 };//A~F

long long int HexToDec_(char *in, int *Dec, int j);
unsigned long long int _Pow(unsigned long long int X, int a);
int findBinDigits_(unsigned long long int s);

int X2B()
{
	int i, j, k;
	unsigned long long int sum = 0;
	char in[17] = { 0 };
	int Hec[17] = { 0 };
	unsigned int Bin[64] = { 0 };
	unsigned int temp[64] = { 0 };


	printf("請輸入欲轉換的數(至多16位數A~F大寫):");
	scanf("%s", &in);

	for (j = 0; in[j] != '\0'; j++);//j���
	printf("0X%s(%d位數)的二進制為\n", in, j);

	sum = HexToDec_(in, Hec, j);

	i = findBinDigits_(sum);//i���G�i����

	for (k = 0; k < i; k++)
	{
		temp[k] = sum % 2;
		sum = sum / 2;
	}
	for (k = 0; k < 64; k++)
		Bin[63 - k] = temp[k];
	for (k = 64 - i; k < 64; k++)
		printf("%d", Bin[k]);
	printf("(%d位數)\n\n", i);

	historyIn_ConversionX2B("Hexadecimal to Binary", in, Bin, i); //Modify for history input
	
	//system("pause");
	return 0;
}

unsigned long long int _Pow(unsigned long long int X, int a)
{
	if (a == 0)
		return 1;
	else
		return X * _Pow(X, a - 1);
}

long long int HexToDec_(char *in, int *Dec, int j)
{
	long long int s = 0;
	int i, f;
	for (i = 0; i <= j; i++)
	{
		for (f = 0; f < 16; f++)
			if (*(in + i) == table_[f])
				*(Dec + i) = f;
	}

	for (i = 0; i < j; i++)
		s = s + *(Dec + i) * _Pow(16, j - i - 1);

	return s;
}

int findBinDigits_(unsigned long long int s)
{
	int i;
	for (i = 0; i < 64; i++)//i���G�i����
	{
		if (s == _Pow(2, i))
			return i + 1;
		else if (s < _Pow(2, i))
			return i;
	}
}

void historyIn_ConversionX2B(char Type[100], char Input[17], unsigned int Output[64], int byte) { //Way to input conversion result to history
    FILE *Pointer;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/history/History_Conversion.txt", "a");
	if (Pointer == NULL) {
		printf("ERROR when inputting history\n");
		fclose(Pointer);
		return 0;
	}
    fprintf(Pointer, "Type   : %s\n", Type);
    fprintf(Pointer, "Input  : %s\n", Input);
    fprintf(Pointer, "Output : ");
	
	unsigned int temp[64] = { 0 };
	int k;

	for (k = 64 - byte; k < 64; k++)
		fprintf(Pointer, "%d", Output[k]);

	fprintf(Pointer, "\n\n");
    fclose(Pointer);
    return 0;
}