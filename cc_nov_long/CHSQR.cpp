#include <bits/stdc++.h>
using namespace std;
int ans[400][400];
int fofk = INT_MIN;
void saveAns(int a[][400], int k){
	int temp = INT_MAX;
	int check = INT_MAX;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if(a[i][j] == 1){
				check = abs(i - (((k+1)/2)-1)) + abs(j - (((k+1)/2)-1));
				if(temp > check)
					temp = check;
			}
		}
	}
	if(fofk < temp){
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				ans[i][j] = a[i][j];
				//cout<<ans[i][j]<<" ";
			}
			//cout<<endl;
		}
		fofk = temp;
	}
	
}

int findSol(int a[][400], int k , int pos, int ctr){
	int x = pos / k;
	int y = pos % k;
	set<int> s;
	// if(ctr == k*k)
	// 	return 1;
	
	// for (int i = 0; i < k; ++i)
	// {
	// 	for (int j = 0; j < k; ++j)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for (int i = 0; i < k; ++i)
	{
		if(a[x][i] != 0){
			s.insert(a[x][i]);
		}
	}
	for (int i = 0; i < k; ++i)
	{
		if(a[i][y] != 0){
			s.insert(a[i][y]);
		}
	}
	int assigned = 1;
	while(assigned <= k){
		if(s.find(assigned) == s.end()){
			a[x][y] = assigned;
			ctr++;
			if(x == k-1 && y == k-1){
				saveAns(a, k);
				//cout<<"hahah";
				// for (int i = 0; i < k; ++i)
				// {
				// 	for (int j = 0; j < k; ++j)
				// 	{
				// 		cout<<a[i][j]<<" ";
				// 	}
				// 	cout<<endl;
				// }
			}
			if(!findSol(a, k, pos+1, ctr)){
				a[x][y] = 0;
				ctr--;
				assigned++;	
			}
			
			else{
				
				return 1;
			}
		}
		else{
			assigned++;
		}
	}
	
	if(assigned > k){
		a[x][y] = 0;
		return 0;
	}

}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int k;
		cin>>k;
		int a[k][400];
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				a[i][j] = 0;
			}
		}
		int temp = findSol(a, k, 0, 0);
		
		// for (int i = 0; i < k; ++i)
		// {
		// 	for (int j = 0; j < k; ++j)
		// 	{
		// 		cout<<ans[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		
	}
	return 0;
}



/* 		Working      */
/*

#include<iostream>
using namespace std;
 
int main(){
    int i,t,k,j;
    cin>>t;
    while(t--){
        cin>>k;
        int c = (k+1)/2-1;
        for(i=1;i<=k;i++){
            for(j=0;j<k;j++){
                cout<<k - ((j+c)%k+1)+1<<" ";
            }
            c++;
            c = c%k;
 
            cout<<endl;
        }
    }
    return 0;
}
 

 */