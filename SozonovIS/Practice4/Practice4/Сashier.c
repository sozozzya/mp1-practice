#include <stdio.h>
#include <string.h>

#define n (sizeof(price)/sizeof(price[0]))

char* product[] = { "Soda", "Milk", "Bread", "Chokolate", "Cheese", "Ice-cream", "Crisps", "Juice", "Salt", "Sugar" };
float price[] = { 79, 45, 23, 119, 65, 99, 85, 59, 59, };
float discount[] = { 10, 0, 0, 30, 45, 0, 60, 10, 0, 5, };
char* barcode[] = { "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010" };
int cnt[n] = { 0 };

void greetings()
{
	printf("Welcome to our store! Please scan the barcode of the selected products and enter 'print' to print the check\n");
}

void description(x)
{
	printf("%s, price: %.0f, discount: %.0f %%\n", product[x], price[x], discount[x]);
}

int scanning()
{
	int i = 0;
	static int tmp;
	char* entered[6];
	printf("\n");
	printf("Scan the barcode: ");
	gets(entered);
	if (strcmp(entered, "print")) 
	{
		tmp = 0;
		for (; i < n; i++) 
		{
			if (strcmp(barcode[i], entered) == 0) 
			{
				description(i);
				cnt[i]++;
				tmp = 1;
			}
		}
		if (tmp == 0)
			printf("Barcode not recognized, please try again\n");
		scanning();
	}
}

void check()
{
	int i = 0;
	float total = 0.0;
	printf("\n");
	printf("*********YOUR CHECK*********\n");
	printf("\n");
	for (; i < n; i++) {
		if (cnt[i] != 0) 
		{
			printf("%s_________%.2f x %d\n", product[i], price[i]*(100-discount[i])/100, cnt[i]);
			total += price[i] * (100 - discount[i]) / 100 * cnt[i];
		}
	}
	printf("\n");
	printf("TOTAL PRISE_________%.2f\n", total);
	printf("\n");
	printf("****************************\n");
	printf("** THANK YOU FOR SHOPPING **\n");
	printf("****************************\n");
}
void main() {
	greetings();
	scanning();
	check();
}