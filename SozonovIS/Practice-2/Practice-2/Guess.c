#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
	int mode, n1, a1, i1 = 0, i2 = 0, k = 2;
	float a2 = 500;
	char ñ;
	do
	{
		printf("Please select mode: ");
		scanf("%d", &mode);
	} while ((mode != 1) && (mode != 2));
	if (mode == 1)
	{
		srand((unsigned int)time(NULL));
		n1 = rand() % 1000;
		printf("I've got a number between 0 and 1000. Try to guess it: \n");
		scanf("%d", &a1);
		if (a1 != n1)
		{
			do
			{
				if (a1 < n1)
				{
					printf("More\n");
				}
				else
				{
					printf("Little\n");
				}
				scanf("%d", &a1);
				i1++;
			} while (a1 != n1);
		}
		printf("Congratulations! You got it\n");
		printf("The number of your attempts=%d\n", i1);
		return 0;
	}
	else
	{
		printf("Please give a number from 0 to 1000\n");
		printf("I think it's %.0f\n", roundf(a2));
		scanf(" %c", &ñ);
		if (ñ != '=')
		{
			do
			{
				if (ñ == '<')
				{
					a2 = a2 * (k - 1) / k;
					k = (k - 1) * 2;
				}
				if (ñ == '>')
				{
					a2 = a2 * (k + 1) / k;
					k = (k + 1) * 2;
				}
				printf("I think it's %.0f\n", roundf(a2));
				scanf(" %c", &ñ);
				i2++;
			} while (ñ != '=');
		}
		printf("Cool! I got it\n");
		printf("The number of my attempts=%d\n", i2);
		return 0;
	}
}