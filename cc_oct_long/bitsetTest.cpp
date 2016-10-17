#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string strL, str2, str3;
    int n;
    cin>>strL>>str2>>str3;
    cin>>n;
    for(long long int i = 0; i < n; ++i)
    {
        strL = strL + str2;
    }
    strL = strL + str3;
	bitset<4000000000UL>& bs = *(new bitset<4000000000UL>(strL));
	cout<<bs.test(0);
	cout<<bs.test(2);
	cout<<bs.test(4);
	cout<<bs.test(6);
	cout<<bs.test(8);
	return 0;
}