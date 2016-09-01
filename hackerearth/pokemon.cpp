#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	unordered_set<int> s;
	int distinct = 0;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}	
	distinct = s.size();
	long long int ans = 0;
	int count = 0;
	
	for(int i = 0; i < n; i++){
		unordered_set<int> newset;
		
		count = 0;
		for(int j = i; j < n; j++){
			
			if(newset.find(a[j]) == newset.end()){
				newset.insert(a[j]);
				count++;
			}
			if(count ==  distinct){
				ans = ans + (n-j) ;
				count = 0;
				break;
			}

		}
		
	}
	cout<<ans<<endl;

	return 0;
}