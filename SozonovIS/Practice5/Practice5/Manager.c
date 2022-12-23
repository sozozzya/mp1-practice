#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "Sorts.h"

int select_sort(int size[], wchar_t** name[], int N)
{
	int i, number, flag;
	long long time1, time2;
	int* size_copy = (int*)malloc(MAX_PATH * sizeof(int));
	wchar_t** name_copy = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
	do
	{
		for (i = 0; i < N; i++)
		{
			size_copy[i] = size[i];
			name_copy[i] = name[i];
		}
		printf("Choose the type of sort: 1 - choice sort, 2 - insert sort, 3 - merge sort  ");
		scanf("%d", &number);

		if ((number < 1) || (number > 3))
		{
			printf("Invalid number.  \n");
			continue;
		}
		else if (number == 1)
		{
			QueryPerformanceCounter(&time1);
			choice_sort(size_copy, name_copy, N);
			QueryPerformanceCounter(&time2);
		}
		else if (number == 2)
		{
			QueryPerformanceCounter(&time1);
			insert_sort(size_copy, name_copy, N);
			QueryPerformanceCounter(&time2);
		}
		else if (number == 3)
		{
			QueryPerformanceCounter(&time1);
			merge_sort(size_copy, name_copy, N);
			QueryPerformanceCounter(&time2);
		}
		if ((number >= 1) || (number <= 3))
			output(size_copy, name_copy, N);
		printf("\nThe time it took to sort = %lld milliseconds\n\n", time2 - time1);
		printf("\n");
		printf("If you want to finish, write 0, if not 1:  ");
		scanf("%d", &flag);
	} while (flag == 1);

}

int form_array(int size[], wchar_t** name[], wchar_t** path[])
{
	WIN32_FIND_DATA names[MAX_PATH];
	WIN32_FIND_DATA File;
	HANDLE hfile;
	char* a = (char*)malloc(MAX_PATH);
	int i = 0, N = 0;;
	printf("Hi! This is the file manager. Please choose the path to the desired derictory:\n");
	scanf("%s", a);
	strcat(a, "\\*.*");
	mbstowcs(path, a, strlen(a) + 1);
	hfile = FindFirstFileW(path, &File);

	FindNextFileW(hfile, &File);
	while (FindNextFileW(hfile, &File) != NULL)
	{
		names[i] = File;
		name[i] = names[i].cFileName;
		size[i] = names[i].nFileSizeLow;
		i++;
	}
	N = i;
	return N;
}

void output(int size_copy[], wchar_t** name_copy[], int N)
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("\n%-60S ", name_copy[i]);
		printf("%d ", size_copy[i]);
	}
}

int main()
{
	int i = 0, N = 0, number, flag = 1;
	int* size = (int*)malloc(MAX_PATH * sizeof(int));
	wchar_t** name = (wchar_t**)malloc(MAX_PATH * sizeof(wchar_t*));
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	N = form_array(size, name, path);
	select_sort(size, name, N);
	return 0;
}