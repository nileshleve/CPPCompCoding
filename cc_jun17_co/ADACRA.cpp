	#include <bits/stdc++.h>

	using namespace std;

	int main(int argc, char const *argv[])
	{
		int t;
		cin>>t;
		while(t-- > 0){
			string s;
			cin>>s;
			int up = 0, down = 0;
			for (int i = 0; i < s.size(); ++i)
			{
				if(s[i] == 'U'){
					if(i == s.size() - 1){
						up++;
						break;
					}
					for (int j = i+1; j < s.size(); ++j)
					{
						if(s[j] == 'U' && j != s.size() - 1)
							continue;
						else{
							i = j - 1;
							up++;
							break;
						}
					}
				}
				else{
					if(i == s.size() - 1){
						down++;
						break;
					}
					for (int j = i+1; j < s.size(); ++j)
					{
						if(s[j] == 'D' && j != s.size() - 1)
							continue;
						else{
							i = j - 1;
							down++;
							break;
						}
					}
				}
			}
			if(up <= down){
				cout<<up<<endl;
			}
			else{
				cout<<down<<endl;
			}
		}
		return 0;
	}