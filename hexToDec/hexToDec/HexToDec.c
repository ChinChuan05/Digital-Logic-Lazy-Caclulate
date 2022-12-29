#include<stdio.h>
#include<stdlib.h>


int main()
{
	//16進制%X 10進制%d 8進制%o 2進制10->2
	//16轉10
	int i, j, de;

	printf("請輸入欲輸入的數值之位數：");
	scanf("%d", &i);

	char X[i + 1];
	printf("請輸入欲轉換的數(%d位數):", i);
	scanf("%s", &X);                  //0~9 = 48~57   A~F = 65~70  a~f = 97~102

	for (j = 0; j < i; j++)
	{
		printf("%d  ", X[j]);
	}
	system("pause");
	return 0;
}

int HexToDec(int)
{
	char X[i + 1];
	printf("請輸入欲轉換的數(%d位數):", i);
	scanf("%s", &X);                  //0~9 = 48~57   A~F = 65~70  a~f = 97~102

	for (j = 0; j < i; j++)
	{
		printf("%d  ", X[j]);
	}
}