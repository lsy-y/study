#include<stdio.h>
#include<time.h>
int main()
{
	char date[32];
	char time[32];
	while (1)
	{
		_strdate(date);
		_strtime(time);
		printf("\r%s %s", date, time);
	}
	return 0;
}