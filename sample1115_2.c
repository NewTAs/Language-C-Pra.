#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_DEGREE 30

#include <stdio.h>
#include <string.h>

void MakeID(void)
{
	FILE* Stream = NULL;

	int User_Array[ARRAY_DEGREE][5];

	char strTemp[255];
	
	char *pStr;
	char *ptr;
	//int CH1 = -1;

	Stream = fopen("databaseUSER.txt", "r");
	if (Stream != NULL)
	{
		//CH1++;
		while (!feof(Stream))
		{
			pStr = fgets(strTemp, sizeof(strTemp), Stream);
			ptr = strtok(pStr, ".");
			while (ptr != NULL) {
				printf("%s\n", ptr);
				ptr = strtok(NULL, ".");
			}
		}
		fclose(Stream);
	}

	int UserID = 0, UserPassword = 0;
	int UserHeight = 0, UserWeight = 0;

	printf("����Ͻ� ID�� �Է����ּ���. (20�� �̳�) :");
	fscanf(stdin, "%d", &UserID);
	//���̵� �ߺ�üũ �ʿ�

	printf("����Ͻ� Password�� �Է����ּ���. (20�� �̳�) :");
	fscanf(stdin, "%d", &UserPassword);
	//��й�ȣ �ߺ�üũ �ʿ�

	printf("Ű�� �Է����ּ���. :");
	fscanf(stdin, "%d", &UserHeight);

	printf("�����Ը� �Է����ּ���. :");
	fscanf(stdin, "%d", &UserWeight);

	Stream = fopen("databaseUSER.txt", "a");
	fprintf(Stream, "%d.%d.%d.%d.\n", UserID, UserPassword, UserHeight, UserWeight);

	fclose(Stream);
}

int main(void)
{
	int Loading = 0;

	printf("GYM PROGRAM!\n");
	printf("� ���� �۾��Ͻðڽ��ϱ�?(1.ȸ������   2.�α���   3.���� ����) :");
	scanf("%d", &Loading);

	switch (Loading) {
	case 1:
		MakeID();
		break;
	case 2:
		printf("���� ���Դϴ�.");
		break;
	case 3:
		printf("���� ���Դϴ�.");
		break;
	}
}