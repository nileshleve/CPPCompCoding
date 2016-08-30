#include<stdio.h>

int main(){
	int x = 5;
	int *ptr = &x;
	int **ptr1 = &ptr;
	printf("%d \t",*ptr);
	
	printf("%d",**ptr1);

	return 0;
}