#include <bits/stdc++.h>
using namespace std;

typedef struct planet{
	int pop;
	int index;
}planet;

bool mySort(planet a, planet b)
{
    return (a.pop > b.pop);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		planet p[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>p[i].pop;
			p[i].index = i+1;
		}
		sort(p, p+n, mySort);


		// for (int i = 0; i < n; ++i)
		// {
		// 	cout<<p[i].pop<<" "<<p[i].index<<endl;

			
		// }
		// cout<<endl;



		set<int> s[n];
		int x, y, i;
		for (i = 0; i < n-1; i++)
		{
			cin>>x;
			cin>>y;
			s[i].insert(i+1);
			s[x-1].insert(y);
			s[y-1].insert(x);
		}
		s[i].insert(i+1);
		// set<int>::iterator it;
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (it = s[i].begin(); it != s[i].end() ; ++it)
		// 	{
		// 		cout<<*it<<" ";
		// 	}
		// 	cout<<endl;
		// }


		for(i = 0; i < n; i++){
			int ans = 0;
			for (int j = 0; j < n; ++j)
			{
				if(s[i].find(p[j].index) == s[i].end()){
					ans = p[j].index;
					break;
				}
			}
			cout<<ans<<" ";
		}
		
	}
	return 0;
}