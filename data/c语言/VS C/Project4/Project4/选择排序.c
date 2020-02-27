#include <stdio.h>
#define SIZE 20
int len = 5;
//选择法排序，由大到小次序
void sort(double a[], int n) {
	int  i, j, maxLoc;
	double temp;
	for (i = 0; i < n - 1; i++)
	{
		maxLoc = i;
		for (j = i + 1; j < n; j++)
			if (a[i] < a[j])
				maxLoc = j;
		if (maxLoc != i)
		{
			temp = a[i];
			a[i] = a[maxLoc];
			a[maxLoc] = temp;
		}
	}
}
//向有序数组中插入一个元素
void insertElement(double *a, int n, double element)
{
	int i = 0, j;
	//寻找插入位置i
	while (a[i++] > element && i < n);
	if (i == n)
	{ //插入在数组的最后
		a[i + 1] = element;
		len++;
	}
	else
	{
		i--;
		//从第i个元素起往后移一个位置，使第i个位置空出来
		for (j = n - 1; j >= i; j--)
			a[j + 1] = a[j];
		a[i] = element; len++;//第i个位置放入element
	}
}
//显示数组的所有元素
void printList(double a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%.1f  ", a[i]);
	printf("\n");
}
void main()
{
	double arr[SIZE];
	int i;
	double ele;
	printf("Input %d elements:\n", len);
	for (i = 0; i < len; i++)
		scanf("%lf", &arr[i]);
	printf("排序前的数组:\n");
	printList(arr, len);
	sort(arr, len);                //排序数组arr
	printf("降序排序后的数组：");
	printList(arr, len);
	printf("\nInput a element to be insered:\n");
	scanf("%lf", &ele);
	insertElement(&arr, len, ele); //插入ele到输入arr中
	printList(arr, len);
	printf("\nInput a element to be insered:\n");
	scanf("%lf", &ele);
	insertElement(&arr, len, ele);//入元素到有序数组中
	printList(arr, len);
}
