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

	unsigned long long int HistoryIn = s; //Attempt to retrieve

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

	historyIn_ConversionD2B("Decimal to Binary", HistoryIn, Bin, i); //Modify for history input
	
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

void historyIn_ConversionD2B(char Type[100], unsigned long long int Input, unsigned int Output[64], int byte) { //Way to input conversion result to history
    FILE *Pointer;
    Pointer = fopen("../Digital-Logic-Lazy-Caclulate/history/History_Conversion.txt", "a");
	if (Pointer == NULL) {
		printf("ERROR when inputting history\n");
		fclose(Pointer);
		return 0;
	}
    fprintf(Pointer, "Type   : %s\n", Type);
    fprintf(Pointer, "Input  : %lld\n", Input);
    fprintf(Pointer, "Output : ");
	
	unsigned int temp[64] = { 0 };
	int k;

	for (k = 0; k < byte; k++)
	{
		temp[k] = Input % 2;
		Input = Input / 2;
	}
	for (k = 0; k < 64; k++)
		Output[63 - k] = temp[k];
	for (k = 64 - byte; k < 64; k++)
		fprintf(Pointer, "%d", Output[k]);

	fprintf(Pointer, "\n\n");
    fclose(Pointer);
    return 0;
}