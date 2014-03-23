#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);


main() 
{
	int a[] = {1,2,4,11,12,19,20};
	int i;

	for (i = 0; i <= 20; ++i) {
		printf("index of %d in array is %d\n", i, binsearch(i, a, 7));
		printf("index of %d in array is %d\n\n", i, binsearch2(i, a, 7));
	}
}

int binsearch(int x, int v[], int n)
{
	int i, j, mid;
	i = 0;
	j = n-1;
	while (i <= j) {
		mid = (i+j)/2;
		if (x < v[mid]) {
			j = mid - 1;
		} else if (x > v[mid]) {
			i = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int i, j, mid;
	i = 0;
	j = n-1;
	
	while (i < j) {
		mid = (i+j)/2;
		if (x <= v[mid]) {
			j = mid;
		} else {
			i = mid + 1;
		}
	}

	mid = (i+j)/2;
	if (x == v[mid]) {
		return mid;
	}

	return -1;
}