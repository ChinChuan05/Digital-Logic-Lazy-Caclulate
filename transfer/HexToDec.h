#include<stdio.h>
#include<stdlib.h>
//#include "historyIn.h"

const int table[16] = { 48,49,50,51,52,53,54,55,56,57,//0~9
				65,66,67,68,69,70 };//A~F

long long int HexToDec(char *in, int *Dec,int j);
int Pow(int X,int a);

int X2D()
{
	//16進制%X 10進制%d 8進制%o 2進制10->2
	//16轉10
	int i, j;
	unsigned long long int sum=0;
	char in[17] = { 0 };
	int Dec[17] = { 0 };

	
	printf("請輸入欲轉換的數(至多16位數A~F大寫):");
	scanf("%s", &in);

	for (j = 0; in[j] != '\0'; j++);//j位數
	printf("%s(%d位數)的十進制為",in ,j);

	sum = HexToDec(in, Dec,j);
	
	printf("%lld\n\n",sum);

	historyIn_ConversionX2D("Hexadecimal to Binary", in, sum); //Modify for history input

	//system("pause");
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

void historyIn_ConversionX2D(char Type[100], char Input[17], unsigned long long int Output) { //Way to input conversion result to history
    FILE *Pointer;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/history/History_Conversion.txt", "a");
	if (Pointer == NULL) {
		printf("ERROR when inputting history\n");
		fclose(Pointer);
		return 0;
	}
    fprintf(Pointer, "Type   : %s\n", Type);
    fprintf(Pointer, "Input  : %s\n", Input);
    fprintf(Pointer, "Output : %lld\n\n", Output);
    fclose(Pointer);
    return 0;
}