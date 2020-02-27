#include<stdio.h>
void main()
{
	int input, passed = 0, failed = 0;
	double avg = 0;
	scanf("%d", &input);
	while (input >= 0)
	{
		avg += input;
		if (input >= 60)
			passed++;
		else failed++;
		scanf("%d", &input);
	}
	avg = avg / (passed + failed);
	printf("passed=%d,failed=%d,average score=%.2f\n", passed, failed, avg);
}