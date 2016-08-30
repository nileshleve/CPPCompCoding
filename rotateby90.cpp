#include<bits/stdc++.h>

using namespace std;
int main(){

	int t;
	scanf("%d",&t);
	while(t-->0){
		int n;
		scanf("%d",&n);
		int a[n][n];
		int b[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}

		for(int j=0;j<n;j++)
			for(int i =0;i<n;i++){
				b[i][j] = a[j][n-1-i];
			}

	for(int i =0;i<n;i++){

		for(int j=0;j<n;j++)
			printf("%d ",b[i][j]);
		//cout<<endl;
	}
	printf("\n");

	}

	return 0;
}