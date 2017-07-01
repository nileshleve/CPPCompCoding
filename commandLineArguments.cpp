#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string str[10];
	for (int i = 0; i < argc - 1; ++i)
	 {
	 	str[i] = argv[i+1];
	 }
	 for (int i = 0; i < argc - 1; ++i)
	 {
	 	cout<<str[i]<<"\n";
	 }
	return 0;
}