#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_DEGREE 30
#include <stdio.h>
#include <string.h>

void MakeID(void)
{
	FILE* Stream = NULL;

	int User_Array[ARRAY_DEGREE][4];
	
	char strTemp[255];
	char *pStr;
	char *ptr;

	Stream = fopen("databaseUSER.txt", "r");
	if (Stream != NULL)
	{
		while (!feof(Stream))
		{
			pStr = fgets(strTemp, sizeof(strTemp), Stream);
			printf("str%s", strTemp);
			printf("pstr%s", pStr);
		}
		fclose(Stream);
	}

	int UserID = 0, UserPassword = 0;
	int UserHeight = 0, UserWeight = 0;

	char Name[20];
	int Age = 0, Gender = 0;
	char IntGender[10];

	printf("사용하실 ID를 입력해주세요. (20자 이내) :");
	fscanf(stdin, "%d", &UserID);
	//아이디 중복체크 필요

	printf("사용하실 Password를 입력해주세요. (20자 이내) :");
	fscanf(stdin, "%d", &UserPassword);
	//비밀번호 중복체크 필요

	printf("키를 입력해주세요. :");
	fscanf(stdin, "%d", &UserHeight);

	printf("몸무게를 입력해주세요. :");
	fscanf(stdin, "%d", &UserWeight);

	Stream = fopen("databaseUSER.txt", "a");
	fprintf(Stream, "%d.%d.%d.%d.\n", UserID, UserPassword, UserHeight, UserWeight);

	fclose(Stream);
}

int main(void)
{
	int Loading = 0;

	printf("GYM PROGRAM!\n");
	printf("어떤 것을 작업하시겠습니까?(1.회원가입   2.로그인   3.정보 보기) :");
	scanf("%d", &Loading);

	switch (Loading) {
	case 1:
		MakeID();
		break;
	case 2:
		printf("개발 중입니다.");
		break;
	case 3:
		printf("개발 중입니다.");
		break;
	}
}