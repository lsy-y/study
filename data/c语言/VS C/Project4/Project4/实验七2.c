#define M 4
#define N 4
int fun(int a[][N])
{
	int i, j, s = 0;
	//求第10行和最后一行的元素之和
	for (j = 0; j < N; j++)
	{
		s += （1）;
		s += （2）;
	}
	//求其他边角元素之和
	for (i = 1; i <= （3）; i++)
	{
		s += a[i][0];
		s += a[i][N - 1];
	}
	return s;
}
void main() {
	int a[M][N] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int i, j, s;
	s = （4）;
	printf("二维数组为\n", s);
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%3d  ", a[i][j]);
		printf("\n");
	}
	printf("周边之和为%d.\n", s);
}
