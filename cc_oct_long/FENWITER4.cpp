#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t-- > 0){
        string str1, str2, str3;
        long long int n;
        long long int count = 0;
        cin>>str1>>str2>>str3;
        cin>>n;
        string strL = str1;
        for (long long int i = 0; i < n; ++i)
        {
            strL = strL + str2;
        }
        strL = strL + str3;
        //bitset<1000> bitset1(strL);
        long long int num = 0;
        long long int arr[strL.size()];
        for (long long int i = 0; i < strL.size(); ++i)
        {
            arr[i] = (int)strL[i] - 48;
        }
        int base = 1;
        for (long long int i = strL.size()-1; i >= 0; i--)
        {
            num += arr[i] * base;
            base = base *2;
        }
        num--;
		while(true){
            // num--;
            cout<<num<<" ";
            num -= (num & (-num));
			if(num <= 0)
                break;
            count++;
		}
        
		cout<<"\n"<<count+1<<endl;
	}
	return 0;
}