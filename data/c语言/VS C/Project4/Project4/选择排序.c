#include <stdio.h>
#define SIZE 20
int len = 5;
//ѡ�������ɴ�С����
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
//�����������в���һ��Ԫ��
void insertElement(double *a, int n, double element)
{
	int i = 0, j;
	//Ѱ�Ҳ���λ��i
	while (a[i++] > element && i < n);
	if (i == n)
	{ //��������������
		a[i + 1] = element;
		len++;
	}
	else
	{
		i--;
		//�ӵ�i��Ԫ����������һ��λ�ã�ʹ��i��λ�ÿճ���
		for (j = n - 1; j >= i; j--)
			a[j + 1] = a[j];
		a[i] = element; len++;//��i��λ�÷���element
	}
}
//��ʾ���������Ԫ��
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
	printf("����ǰ������:\n");
	printList(arr, len);
	sort(arr, len);                //��������arr
	printf("�������������飺");
	printList(arr, len);
	printf("\nInput a element to be insered:\n");
	scanf("%lf", &ele);
	insertElement(&arr, len, ele); //����ele������arr��
	printList(arr, len);
	printf("\nInput a element to be insered:\n");
	scanf("%lf", &ele);
	insertElement(&arr, len, ele);//��Ԫ�ص�����������
	printList(arr, len);
}
