#include <bits/stdc++.h>
using namespace std;

bool is_perfect_cube(int n) {
    int root(round(cbrt(n)));
    return n == root * root * root;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int k, c;
		cin>>k;
		cin>>c;
		string ans = "NO";
		int total = k*k*k;
		double temp = 0;
		int i = 1;
		int a = total - c;
		while((a*a) > temp)
		{
			temp = 1 + (double)((double)(total*i)/(double)(a));
			if(temp == (double)a*a){
				cout<<temp;
				cout<<endl<<i<<endl;
				ans = "YES";
			}
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}