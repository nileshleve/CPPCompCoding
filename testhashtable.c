#include<stdio.h>


int main(){
	int x=5,y=10;
	struct Hashtable *HT = CreateHashTable();
	HT.insert(x,y);
	y=0;
	y=HT.get(x);

	printf("%d",y);
	
	return 0;

}