#include<stdlib.h>
#include<stdio.h>
#include <math.h>
void main() {

	FILE *f = fopen("input.txt", "r");
	double a[1000];
	int n = 0;
	float d;
	while (fscanf(f, "%f", &d)!=EOF)
	{	
			a[n] = d;
			n++;
	}
	fclose(f);
	double **dp = (double**)malloc(sizeof(double*)*(n+1));
	for (int i = 0; i <= n; i++)
	{
		dp[i] = (double*)malloc(sizeof(double)*(n+1));
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = -100000;
		}
	}
	int max = 1;
	int *index= (int*)malloc(sizeof(int)*(n+1));
	for (int i = 0; i <= n; i++)
	{
		index[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = max; j > 0; j--)
		{
			for (int h = 0; h < index[j];h++)
			{
				if (dp[j][h] <= a[i])
				{
					dp[j + 1][index[j + 1]] = a[i];
					index[j + 1]++;
					if (max == j)
					{
						max++;
					}
					break;
				}
			}
		}
		dp[1][index[1]] = a[i];
		index[1] ++;
	}
	for (int i = 0; i <= n; i++)
	{
		dp[i] = (double*)malloc(sizeof(double)*(n + 1));
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = -100000;
		}
	}
	int max2 = 1;
	index = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
	{
		index[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = max2; j > 0; j--)
		{
			for (int h = 0; h < index[j]; h++)
			{
				if (dp[j][h] >= a[i])
				{
					dp[j + 1][index[j + 1]] = a[i];
					index[j + 1]++;
					if (max2 == j)
					{
						max2++;
					}
					break;
				}
			}
		}
		dp[1][index[1]] = a[i];
		index[1] ++;
	}
	if(max>max2)
	printf("%d\n", max);
	else
   printf("%d\n", max2);
}