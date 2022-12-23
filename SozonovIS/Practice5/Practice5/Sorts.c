#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Sorts.h"

void choice_sort(int a[], wchar_t** b[], int N)
{
	int i, j, min, ind, tmp;
	wchar_t* t = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	for (i = 0; i < N; i++)
	{
		min = a[i];
		ind = i;
		for (j = i + 1; j < N; j++)
			if (a[j] < min)
			{
				min = a[j];
				ind = j;
			}
		tmp = a[ind];
		a[ind] = a[i];
		a[i] = tmp;

		t = b[ind];
		b[ind] = b[i];
		b[i] = t;
	}
}

void insert_sort(int a[], wchar_t** b[], int N)
{
	int i, j, tmp, k;
	wchar_t* t = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	for (i = 1; i < N; i++)
	{
		tmp = a[i];
		t = b[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			b[j + 1] = b[j];
			j--;

		}
		a[j + 1] = tmp;
		b[j + 1] = t;

	}
}

void merge(int get[], wchar_t** name[], int l, int mid, int r)
{
	int k = 0, i = 0, j = 0;
	int N = mid - l;
	int M = r - mid + 1;

	int* c = (int*)malloc((r - l + 1) * sizeof(int));
	wchar_t** name_c = (wchar_t**)malloc((r - l + 1) * sizeof(wchar_t*));
	i = l;
	j = mid;
	while (((i - l) < N) && ((j - mid) < M))
	{
		if (get[i] < get[j]) {
			c[k] = get[i];
			name_c[k] = name[i];
			k++;
			i++;
		}
		else
		{
			c[k] = get[j];
			name_c[k] = name[j];
			k++;
			j++;
		}
	}
	while ((i - l) < N)
	{
		c[k] = get[i];
		name_c[k] = name[i];
		k++;
		i++;
	}
	while ((j - mid) < M)
	{
		c[k] = get[j];
		name_c[k] = name[j];
		k++;
		j++;
	}

	for (i = l; i < r + 1; i++)
	{
		get[i] = c[i - l];
		name[i] = name_c[i - l];
	}
}

void merge_sort(int a[], wchar_t** name[], int N)
{

	merge_sort_lr(a, name, 0, N - 1);
}

void merge_sort_lr(int a[], wchar_t** name[], int l, int r)
{
	int mid;
	if (l >= r)
		return;
	mid = l + (r - l) / 2;
	merge_sort_lr(a, name, l, mid);
	merge_sort_lr(a, name, mid + 1, r);
	merge(a, name, l, mid + 1, r);
}