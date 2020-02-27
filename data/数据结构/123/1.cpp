#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<string.h>

int main(void)
{
    time_t current = time(NULL);
    char* string;

    /*把日期和时间转为字符串*/
    string = ctime(¤t);
    if (current == (time_t)-1)
    {
        printf("Fail to get the current time!\n");
    }

    printf("The current time is %s", string);
    printf("(%d seconds since the Epoch)\n",current);
}
