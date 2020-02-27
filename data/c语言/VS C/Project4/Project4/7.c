#include <stdio.h>
void main() {
	int x, y;
	x = 5 > 3 || 3 * 4 < 6 && !(5 > 3);
	y = 2 == 6 && 9 > 8 + 4 || 5 + 6 < 7 + 4 && !x;
	printf("x=%d, y=%d\n", x, y);
}
