#include <stdio.h>
#include <math.h>

int InRectangle(float pt[2], float rect[4]) {
	float x = (rect[0] + rect[2]) / 2;
	float y = (rect[1] + rect[3]) / 2;
	float a = fabs(rect[0] - x);
	float b = fabs(rect[1] - y);
	float c = fabs(pt[0] - x);
	float d = fabs(pt[1] - y);
	if (a >= c && b >= d) {
		return 1;
	}
	return 0;
}
