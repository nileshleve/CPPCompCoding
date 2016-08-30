#include<iostream>
#include<cstdio>
#include<map>


using namespace std;

int main(){
	int a[] = {2, 5, 2, 8, 5, 6, 8, 8};
	map<int, int> m1;
	int firstoccurence[10];
	for(int i=0;i<10;i++){
		firstoccurence[i]=-1;
	}
	
	for(int i = 0;i<sizeof(a)/sizeof(a[0]);i++){
		if(m1.find(a[i])==m1.end()){
			firstoccurence[a[i]] = i;
		}
		m1[a[i]]++;

	}
	map <int, int>::iterator it;

	for(it = m1.begin(); it!=m1.end();it++){
		cout<<it->first<<" "<<it->second<<" \n";
	}

	for(int i=0;i<10;i++){
		cout<<firstoccurence[i]<<"\t";
	}
	cout<<endl;



	return 0;
}