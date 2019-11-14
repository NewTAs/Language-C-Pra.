#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_DEGREE 30
#include <stdio.h>
#include <string.h>

void MakeID(void)
{
	struct User_Info {
		char Name[20];
		int Age;
		char IntGender[20];
		char UserID[20];
		char UserPassword[20];
	};
	struct User_Info UI;

	FILE* Stream = NULL;

	char User_Array[ARRAY_DEGREE][5];
	char strTemp[255];
	char *pStr;
	char *ptr;
	int Checknum_1 = -1;

	Stream = fopen("databaseUSER.txt", "r");
	if (Stream != NULL)
	{
		while (!feof(Stream))
		{
			Checknum_1++;
			fscanf(Stream, "%s.%d.%s.%s.%s\n", &UI.Name, &UI.Age, &UI.IntGender, &UI.UserID, &UI.UserPassword);
			
			User_Array[Checknum_1][0] = UI.Name;
			printf("%s\n", User_Array[Checknum_1][0]);
			User_Array[Checknum_1][1] = UI.Age;
			printf("%s\n", User_Array[Checknum_1][1]);
			strcpy(User_Array[Checknum_1][2], UI.IntGender);
			strcpy(User_Array[Checknum_1][3], UI.UserID);
			strcpy(User_Array[Checknum_1][4], UI.UserPassword);

			/*
			pStr = fgets(strTemp, sizeof(strTemp), Stream);
			//ptr = strtok(pStr, ".");

			if (pStr == NULL)
				break;
			else
			{
				int Checknum_2 = 0;
				ptr = strtok(strTemp, ".");
				while (ptr != NULL) {
					
					ptr = strtok(NULL, ".");
					Checknum_2++;
				}
			}*/
		}
		fclose(Stream);
	}

	char Name[20];
	int Age = 0, Gender = 0;
	char IntGender[10], UserID[20], UserPassword[20];

	printf("이름을 입력해주세요. (10자 이내) :");
	fscanf(stdin, "%s", &Name);

	printf("나이를 입력해주세요. :");
	fscanf(stdin, "%d", &Age);

	printf("성별을 선택해주세요.(남자:1, 여자:2) :");
	fscanf(stdin, "%d", &Gender);
	switch (Gender) {
	case 1:
		strcpy(IntGender, "Man");
		break;
	case 2:
		strcpy(IntGender, "Woman");
		break;
	}

	printf("사용하실 ID를 입력해주세요. (20자 이내) :");
	fscanf(stdin, "%s", &UserID);
	//아이디 중복체크 필요

	printf("사용하실 Password를 입력해주세요. (20자 이내) :");
	fscanf(stdin, "%s", &UserPassword);
	//비밀번호 중복체크 필요

	Stream = fopen("databaseUSER.txt", "a");
	fprintf(Stream, "%s.%d.%s.%s.%s.\n", Name, Age, IntGender, UserID, UserPassword);

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