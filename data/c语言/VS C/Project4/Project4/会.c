#include<stdio.h>
#define SIZE 10
int N = 5;
//����
void sort(int a[], int n)
{
	int i, j, minLoc;
	int temp;
	for (i = 0; i < n - 1; i++)
	{
		minLoc = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[minLoc])
				minLoc = j;
		if (minLoc != i)
		{
			temp = a[i];
			a[i] = a[minLoc];
			a[minLoc] = temp;
		}
	}
}
//���һ������
void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");

}
//����һ������
void insertElement(int *a, int ele, int n)
{
	int i = 0, j;
	while (a[i++] < ele&&i < n);
	if (i == n)
	{
		a[i] = ele;
		n++;
	}
	else
	{
		i--;
		for (j = n - 1; j >= i; j--)
			a[j + 1] = a[j];
		a[i] = ele;
		n++;

	}
}
void main()
{
	int a[SIZE];
	int i;
	int ele;
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, N);
	print(a, N);
	printf("����Ҫ��������֣�");
	scanf("%d", &ele);
	insertElement(a, ele, N);
	print(a, N);


}