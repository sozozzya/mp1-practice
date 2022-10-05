#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	setlocale(LC_NUMERIC, "C");
	float x1, y1, r1, x2, y2, r2, d;
	printf("Введите координаты центра первой окружности и её радиус: ");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Введите координаты центра второй окружности и её радиус: ");
	scanf("%f %f %f", &x2, &y2, &r2);
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (d==0)
	{
		if (r1 == r2)
		{
			printf("Окружности имеют бесконечное множество общих точек");
			return 0;
		}
		else
		{
			printf("Окружности не имеют ни одной общей точки");
			return 0;
		}
	}
	else
	{
		if ((d == abs(r2 - r1)) || (d == r2 + r1))
		{
			printf("Окружности имеют ровно одну общую точку");
			return 0;
		}
		if ((d > abs(r2 - r1)) && (d < r2 + r1))
		{
			printf("Окружности имеют ровно две общие точки");
			return 0;
		}
		else
		{
			printf("Окружности не имеют ни одной общей точки");
			return 0;
		}
	}
}
