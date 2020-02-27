#include<stdio.h>
void bubblesort(int values[],int size)
{
	int pass, i, temp;
	for (pass = 1; pass <= size - 1; pass++)
	{
		for (i = 0; i <= size - 1 - pass; i++)
			if (values[i] > values[i + 1])
			{
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
			}
	}
}
void print(int values[], int size)
{
	int i;
}