#include<stdio.h>

int main()
{
	int a[20] = {0,1,0,2,0,0,1,1,0,2,2,2,1,2,0,2,0,2,0,1};
	int ac=0;
	int b=0;
	int c=0;
	int i=0;
	int temp=0;
	int temp1=0;
	for(i=0;i<20;i++){
		if(a[i]==0){
			ac++;
		}
		else if(a[i]==1){
			b++;
		}
		else{
			c++;
		}
	}

	//int length = sizeof(a)/sizeof(int);
	//printf("%d\t%d\t%d\n",ac,b,c);
	
	for(i=0;i<ac;i++){
		a[i] = 0;
	}

	temp = ac+b;
	temp1 = ac+b+c;

	for(i=ac;i<temp;i++){
		a[i] = 1;
	}

	for(i=temp;i<temp1;i++){
		a[i] = 2;
	}


	for(i=0;i<20;i++){
		printf("%d\t",a[i]);
	}

	return 0;
}