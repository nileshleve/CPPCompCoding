#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int isRightTriangle(int *P1,int *P2, int *P3);
int main(){
	int a=-6,b=3,c=-1;
	printf("%d",isRightTriangle(&a,&b,&c));

	return 0;
}


int isRightTriangle(int *P1,int *P2, int *P3){
	int d1,d2,d3;
	int hyp;
	int a,b;
	d1 = abs(*P1 - *P2);
	int x=100;
	double test = sqrt(x);

	printf("%f\t",test);
	d2 = abs(*P2 - *P3);
	printf("%d\t",d2);
	d3 = abs(*P1 - *P3);
	printf("%d\n",d3);


	d1 = 3;
	d2 = 4;
	d3 = 5;

	if(d1>d2 && d1>d3){
		hyp =d1;
		a=d2;
		b=d3;
	}

	if(d2>d1 && d2>d3){
		hyp =d2;
		a=d1;
		b=d3;
	}

	if(d3>d1 && d3>d2){
		hyp =d3;
		a=d1;
		b=d2;
	}

	int sum = (a*a + b*b);
	if(sum == hyp*hyp){
		return 1;
	}
	else
		return 0;
	


}