#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>



int main() {

	FILE *f = fopen("input.txt", "r");
	double ** matr;
	char *arr[1000];
	char * st = "";
	int n = 0;
	while (st != NULL)
	{
		arr[n] = (char*)malloc(sizeof(char)*1000);
		st = fgets(arr[n], 1000, f);
		n++;
	}
	n--;
	fclose(f);
	matr = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++)
	{
		matr[i] = (double*)malloc(n * sizeof(double));
		int in = 0;
		for (int j = 0; j < n; j++)
		{
			char str[1000];
			int index = 0;
			while (arr[i][in] != ' ' && arr[i][in]!='\n')
			{
				str[index] = arr[i][in];
				index++;
				str[index] = '\0';
				in++;
			}
			in++;
			matr[i][j] = atof(str);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (matr[i][i] == 0)
		{
			for (int j = i; j < n;j++)
			{
				if (matr[j][i] != 0)
				{
					double * p = matr[j];
					matr[j] = matr[i];
					matr[i] = p;
					break;
				}
			}
		}
		if(matr[i][i] != 0)
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				double p = matr[j][i];
				for (int j1 = 0; j1 < n; j1++)
				{
					matr[j][j1] = matr[j][j1] - (p*matr[i][j1]) / matr[i][i];
				}
			}
		}
	}
	f = fopen("output.txt", "w");

	double* a = (double*)malloc(sizeof(double)*n);
	double k = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	int p = -1;
	for (int i = 0; i < n; i++)
	{
		if (matr[i][i]==0)
		{
			p = i;
			break;
		}
	}
	if (p != -1)
	{
		for (int i = 0; i < n; i++)
		{
			if (matr[i][i] != 0)
			{
				a[i] = -matr[i][p]/ matr[i][i];
			}
		}
	}
	if (p == -1)
	{
		fprintf(f, "%s\n", "Единственное решение");
	}
	else
	{
		fprintf(f, "%s\n", "Бесконечно много решений");
		fprintf(f, "%s\n", "Вот одно из них:");
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "x%d=%f\n",i, a[i]);
	}
	fclose(f);
	for (int i = 0; i < n; i++)
	{
		free(matr[i]);
	}
	free(matr);
}