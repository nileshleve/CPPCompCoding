#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int n;
	while(t-- > 0){
		cin>>n;
		int ans[n];
		int c[n];
		vector<int> v[n];
		int temp;
		for (int i = 0; i < n; i++)
		{
			cin>>c[i];
			ans[i] = c[i];

			for (int j = 0; j < c[i]; j++)
			{
				cin>>temp;
				v[i].push_back(temp);
			}
			//sort(v[i].begin(), v[i].end());
		}

		vector<int>::iterator it;
		

		/*for (int i = 0; i < n; i++)
		{
			for (it = v[i].begin(); it != v[i].end(); it++)
			{
				cout<< *it;
			}
			cout<<endl;
		}*/

		map<int, int> m1[n];
		for (int i = 0; i < n; i++)
		{
			for(it = v[i].begin(); it != v[i].end(); it++){
				m1[i][*it]++;
			}
			
		}
		map<int, int>::iterator mit;
		for (int i = 0; i < n; i++)
		{	
			int count = 0;
			while(true){
				count = 0;
				for(mit = m1[i].begin(); mit != m1[i].end(); mit++){
					if(mit->second > 0){
						count++;
						mit->second--;
					}

				}
				if(count == 6)
					ans[i] += 4;
				else if(count == 5)
					ans[i] += 2;
				else if(count == 4)
					ans[i] += 1;
				else{
					count = 0;
					break;

				}
					
			}
			
		}

			
		
		int maxindex;
		int max = INT_MIN;
		for(int i = 0;i < n; i++){
			//cout<<ans[i]<<"  ";
			if(ans[i] > max){
				maxindex = i;
				max = ans[i];
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if(ans[i] == max){
				count++;
			}
		}
		if(count > 1){
			cout<<"tie"<<endl;
			
		}
		else if(maxindex == 0){
			cout<<"chef"<<endl;
			
		}
		else{
			cout<<maxindex+1<<endl;
			
		}


	}
	return 0;
}