#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	setlocale(LC_NUMERIC, "C");
	float x1, y1, r1, x2, y2, r2, d;
	printf("Enter the coordinates of the center of the first circle and its radius: ");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Enter the coordinates of the center of the second circle and its radius: ");
	scanf("%f %f %f", &x2, &y2, &r2);
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (d==0)
	{
		if (r1 == r2)
		{
			printf("Circles have infinite set of common points");
			return 0;
		}
		else
		{
			printf("Circles have no common point");
			return 0;
		}
	}
	else
	{
		if ((d == abs(r2 - r1)) || (d == r2 + r1))
		{
			printf("Circles have exactly one common point");
			return 0;
		}
		if ((d > abs(r2 - r1)) && (d < r2 + r1))
		{
			printf("Circles have exactly two common points");
			return 0;
		}
		else
		{
			printf("Circles have no common point");
			return 0;
		}
	}
}
