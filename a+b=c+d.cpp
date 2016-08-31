#include <bits/stdc++.h>
using namespace std;

struct node{
	int x1;
	int x2;
	int x3;
	int x4;
};

bool mycomp(struct node one, struct node two){
	if(one.x1 == two.x1)
		return (one.x2 < two.x2);
	else
		return (one.x1 < two.x2);
}

int main(){
	int t;
	cin>>t;
	int n;
	while(t-- >0){
		cin>>n;
		int a[n];
		for(int i= 0 ;i <n ;i++){
			cin>>a[i];
		}
		int check = 0;
		struct node arr[n];
		int k = 0;
		int sum = 0;
		map<int, pair<int, int> > m;
		
		for(int i = 0; i<n;i++){
			for (int j = i+1; j < n; j++)
			{	
				sum = a[i] + a[j];
				if(m.find(sum) == m.end()){
					m[sum] = make_pair(i, j);
				}
				else{
					pair<int, int> p = m[sum];
					//cout<< p.first <<" "<< p.second <<" " << i <<" "<< j <<endl;
					check = 1;
					arr[k].x1 = p.first;
					arr[k].x2 = p.second; 
					arr[k].x3 = i;
					arr[k++].x4 = j;
				}
			}
		}
		if(check == 0)
			cout<<"no pairs"<<endl;
		else{
			sort(arr, arr+k-1, mycomp);
			cout<<arr[0].x1<<" "<<arr[0].x2<<" "<<arr[0].x3<<" "<<arr[0].x4<<endl;
		}
	
	}

	return 0;
}