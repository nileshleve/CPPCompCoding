#include<stdio.h>

int main(){
	int test[3][2] = {{1,4},{2,5},{2,8}};
	int i,j;
	for (i = 0 ; i < 3; i++) {
	    for (j = 0; j < 2; j++) {
	        printf("%d\t", *(*(test+i)+j));
	    }
	    printf("\n");
	}

	return 0;
}