#define M 4
#define N 4
int fun(int a[][N])
{
	int i, j, s = 0;
	//���10�к����һ�е�Ԫ��֮��
	for (j = 0; j < N; j++)
	{
		s += ��1��;
		s += ��2��;
	}
	//�������߽�Ԫ��֮��
	for (i = 1; i <= ��3��; i++)
	{
		s += a[i][0];
		s += a[i][N - 1];
	}
	return s;
}
void main() {
	int a[M][N] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int i, j, s;
	s = ��4��;
	printf("��ά����Ϊ\n", s);
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
			printf("%3d  ", a[i][j]);
		printf("\n");
	}
	printf("�ܱ�֮��Ϊ%d.\n", s);
}
