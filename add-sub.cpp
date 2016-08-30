#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n;
		int k;
		cin>>n;
		cin>>k;
		int min= INT_MAX;
		int max= INT_MIN;
		int a[n];
		for(int i = 0; i<n;i++){
			cin>>a[i];
			if(min>a[i])
				min = a[i];
			if(max<a[i])
				max = a[i];

		}	
		
		
		int mincost = INT_MAX;
		for(int i=min;i<=max;i++){
			int costs[n];
			int p = 0;
			int temp = 0;
			for(int j =0;j<n;j++){
				if(a[j]>i){
					temp+=(a[j]-i)*5;
				}
				else{
					temp+=(i-a[j])*3;
				}
				costs[p++] = temp;
				//cout<<temp<<"\t";
				temp = 0;

			}
			sort(costs, costs+n);
			temp = 0;
			for(int j=0;j<k;j++){
				temp+=costs[j];
			}
			if(mincost>temp){
				mincost = temp;
			}
		}
		cout<<mincost<<endl;

	}


	return 0;
}