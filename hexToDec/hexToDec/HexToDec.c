#include<stdio.h>
#include<stdlib.h>


int main()
{
	//16�i��%X 10�i��%d 8�i��%o 2�i��10->2
	//16��10
	int i, j, de;

	printf("�п�J����J���ƭȤ���ơG");
	scanf("%d", &i);

	char X[i + 1];
	printf("�п�J���ഫ����(%d���):", i);
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
	printf("�п�J���ഫ����(%d���):", i);
	scanf("%s", &X);                  //0~9 = 48~57   A~F = 65~70  a~f = 97~102

	for (j = 0; j < i; j++)
	{
		printf("%d  ", X[j]);
	}
}