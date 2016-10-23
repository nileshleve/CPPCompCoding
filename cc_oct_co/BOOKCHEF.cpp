#include <bits/stdc++.h>

using namespace std;

typedef struct post{
	int f;
	int p;
	string s;
}post;

bool sortbysec(post a, post b)
{
    return (a.p > b.p);
}

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	int temp;
	int x = 0, y = 0;
	set<int> special;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		special.insert(temp);
	}
	post posts1[m];
	post posts2[m];
	for (int i = 0; i < m; ++i)
	{
		cin>>temp;
		if(special.find(temp) != special.end()){
			posts1[x].f = temp;
			cin>>posts1[x].p;
			cin>>posts1[x].s;
			x++;
		}
		else{
			posts2[y].f = temp;
			cin>>posts2[y].p;
			cin>>posts2[y].s;
			y++;
		}
		
	}
	sort(posts1, posts1 + x, sortbysec);
	for (int i = 0; i < x; ++i)
	{
		cout<<posts1[i].s<<endl;
	}
	sort(posts2, posts2 + y, sortbysec);
	for (int i = 0; i < y; ++i)
	{
		cout<<posts2[i].s<<endl;
	}
	return 0;
}