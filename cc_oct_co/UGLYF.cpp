#include <bits/stdc++.h>

using namespace std;
int getMin(int x, int y){
	return (x < y) ? x : y; 
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		string str1;
		string str2;
		cin>>str1;
		cin>>str2;
		int size1 = str1.size();
		int size2 = str2.size();
		int ans = INT_MAX;
		int temp = 0;
		int l1 = 0, l2 = 0, l3 = 0, l4 = 0;

		vector<int> vec[26];
		for (int i = 0; i < size2; ++i)
		{
			vec[str2[i] - 'A'].push_back(i);
		}
		vector<int>::iterator it;
		for (int i = 0; i < size1; ++i)
		{
			int index = str1[i] - 'A';
			for (it = vec[index].begin(); it < vec[index].end(); ++it)
			{
				if(str1[i] == str2[*it]){
					l1 = i;
					l3 = size1 - i - 1;
					l2 = *it;
					l4 = size2 - *it - 1;
					temp = abs(l1 - l2) + abs(l2 - l3) + abs(l3 - l4) + abs(l4 - l1);
					if(ans > temp)
						ans = temp;
				}
			}
			// for (int j = 0; j < size2; ++j)
			// {
			// 	if(str1[i] == str2[j]){
			// 		l1 = i;
			// 		l3 = size1 - i - 1;
			// 		l2 = j;
			// 		l4 = size2 - j - 1;
			// 		temp = abs(l1 - l2) + abs(l2 - l3) + abs(l3 - l4) + abs(l4 - l1);
			// 		if(ans > temp)
			// 			ans = temp;
			// 	}
			// }
		}
		cout<<ans<<endl;
	}
	return 0;
}