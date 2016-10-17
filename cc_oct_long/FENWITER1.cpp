#include <bits/stdc++.h>
using namespace std;
int start_s=clock();

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
        // bitset<10000000> bitset1(strL);
        // bitset<10000000> bitset2(strL);
        // bitset<10000000> bitset3(strL);
        bitset<400000000UL>& bitset1 = *(new bitset<400000000UL>(strL));
        bitset<400000000UL>& bitset2 = *(new bitset<400000000UL>(strL));
        bitset<400000000UL>& bitset3 = *(new bitset<400000000UL>(strL));


        int carry;
        int check =1;
		while(true){

			carry = 1;
			if(check == 1){
				for (long long int i = 0; i < strL.size(); i++)
	            {
	                if(bitset1.test(i) && carry == 1){
	                    bitset1.reset(i);
	                    carry = 1;
	                }
	                else if(!bitset1.test(i) && carry == 1){
	                    bitset1.set(i);
	                    carry = 0;
	                }
	            }
	            check = 0;
			}
			else{
				bitset1 = bitset3;
			}
			
            bitset1 = bitset1 & bitset2;
            if(bitset1.none())
            	break;
            bitset3 = bitset1;
            carry = -1;
            for (long long int i = 0; i < strL.size(); i++)
            {
                if(!bitset1.test(i) && carry == -1){
                    bitset1.set(i);
                    carry = 0;
                }
                else if(bitset1.test(i) && carry == -1){
                    bitset1.reset(i);
                    carry = 0;
                }
                else if(bitset1.test(i)){
                    bitset1.reset(i);
                    break;
                }
                else{
                    bitset1.set(i);
                }
                
            }
            bitset2 = bitset1;
            count++;
		}
		cout<<count+1<<endl;
	}
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}