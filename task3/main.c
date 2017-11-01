#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int comp(const void* one,const void* two)
{	
	char *a = *(char**)one;
	char *a1=*(char**)two;
	int k=strcmp(a, a1);
	if(k > 0)
	return 1;
	else
	{
		return 0;
	}

}
int main() {
	FILE *f = fopen("input.txt", "r");
	char * arr1[100];
	char * arr2[100];
	char * st = "";
	int i = 0;
	while (st != NULL)
	{
		arr1[i] = (char*)malloc(sizeof(char)*1000);
		st = fgets(arr1[i], 1000, f);
		i++;
	}
	i--;
	fclose(f);
	f = fopen("output.txt", "r");
	st = "";
	int j = 0;
	while (st != NULL)
	{
		arr2[j] = (char*)malloc(sizeof(char) * 1000);
		st = fgets(arr2[j], 1000, f);
		j++;
	}
	j--;
	fclose(f);
	qsort(arr1, i,sizeof(char*),comp);
	qsort(arr2, j, sizeof(char*) , comp);
	int ki = 0;
	bool ok = true;
	for (int k1 = 0; k1 < j; k1++)
	{
		if (strcmp(arr1[ki], arr2[k1]) > 0)
		{
			ok = false;
			break;
		}
		else
		{
			if (ki == i)
			{
				ok = false;
				break;
			}
			if (strcmp(arr1[ki], arr2[k1]) < 0)
			{
				ki++;
				k1--;
			}
		}
	}

	if (ok)
		printf("true\n");
	else
	{
		printf("false\n");
	}

}