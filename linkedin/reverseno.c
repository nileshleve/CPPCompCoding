#include<stdio.h>

int main()
{
	char a[] = {'1', '0', '0', '2'};
	int r = 0;
	int i;
	int temp;
	for (i = 3; i >= 0; --i)
	{
		temp = atoi(a[i]);
		r = r*10 + temp;
	}
	printf("%d ", r);
	return 0;
}