#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char arr1[100][100];
char arr2[100][100];

int k1 = 0;
int k2 = 0;
int Concatstr(char * st)
{
	for (int i = 0; i < k1; i++)
	{
		if (strncmp(st, arr1[i], strlen(arr1[i])) == 0)
		{
			char *str = (char*)malloc(sizeof(char)*(strlen(st) - strlen(arr1[i])));
			str[strlen(st) - strlen(arr1[i])] = '\0';
			// strcpy(str, st + strlen(arr1[i])/*strlen(st)- strlen(arr1[i])*/);
			 //strcpy(str, &st[strlen(arr1[i])]);
			//str=(char*)memcpy(&str,&st[strlen(arr1[i])], sizeof(char)*(strlen(st) - strlen(arr1[i])));
			for (int j = strlen(arr1[i]); j < strlen(st); j++)
			{
				str[j - strlen(arr1[i])] = st[j];
			}
			if (strlen(str)==0)
			{
				return 1;
			}
			else
			{
				if (Concatstr(str))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
void main() {
	FILE *f = fopen("input.txt", "r");
	char * st1 = (char*)malloc(sizeof(char)*10000);
	char * st2 = (char*)malloc(sizeof(char) * 10000);
	int i = 0;
	 fgets(st1, 100000, f);
	 fgets(st2, 100000, f);
	 fclose(f);
	 while (st1[i] != '\0')
	 {
		 int k = 0;
		 while (st1[i] != '\0' && st1[i] != ' '  && st1[i] != '\n')
		 {
			 arr1[k1][k] = st1[i];
			 k++;
			 i++;
		 }
		 arr1[k1][k] = '\0';
		 k1++;
		 if (st1[i] != '\0')
		 {
			 i++;
		 }
	 }
	 i = 0;
	 while (st2[i] != '\0')
	 {
		 int k = 0;
		 while (st2[i] != '\0' && st2[i] != ' '&& st2[i] != '\n')
		 {
			 arr2[k2][k] = st2[i];
			 k++;
			 i++;
		 }
		 if (st2[i] != '\0' )
		 {
			 i++;
		 }
		 k2++;
	 }
	 char * ans[100];
	 int count = 0;
	//sort(arr1, arr1 + k1, comp);
	//sort(arr2, arr2 + k2, comp);
	for (int i = 0; i < k2; i++)
	{
		if (!Concatstr(arr2[i]))
		{
			ans[count] = arr2[i];
			count++;
		}
	}

	if (count == 0)
		printf("true\n");
	else
	{
		printf("false\n");
	    printf("uncorrect strings:\n");
		for (int i = 0; i < count; i++)
		{
			printf("%s\n",ans[i]);
		}
	}
}