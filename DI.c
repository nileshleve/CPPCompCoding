#include<stdio.h>


int main(){

	char a[8];
	int countD=0,countI=0;
	int i,j,k=0;
	int W[8]={0};
	
	scanf("%s",a);
	//printf("%s",a);

	for(i=0;i<8;i++){
		if(a[i]=='D'){
			countD++;
			for(j=i+1;j<8;j++){

				if(a[j]=='D'){
					countD++;
				}
				else{
					break;
				}

			}
			//printf("%d",j);
			W[k++] = countD;
			
			i = i+countD-1;
			countD = 0;
		}

		else{
			countI++;
			for(j=i+1;j<8;j++){
				if(a[j]=='I'){
					countI++;
				}
				else{
					break;
				}
			}
			
			W[k++] = countI;
			
			i = i+countI-1;
			countI=0;
		}
		
	
	}

	for(i=0;i<8;i++){
		if(W[i]!=0){

		}
	}

	for(i=0;i<8;i++){
		printf("%d\n",W[i]);
	}

	return 0;
}