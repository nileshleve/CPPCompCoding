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
        int count = 0;
        cin>>str1>>str2>>str3;
        cin>>n;
        string strL = str1;
        for (long long int i = 0; i < n; ++i)
        {
            strL = strL + str2;
        }
        strL = strL + str3;
        int carry = 1;
        long long int countzeroes = 0;
        int arr[strL.size()];
        int arr1[strL.size()];
        for (long long int i = 0; i < strL.size(); ++i)
        {
            arr[i] = (int)strL[i] - 48;
            arr1[i] = (int)strL[i] - 48;
        }
        carry = 1;
        for (long long int i = strL.size()-1; i >= 0; i--)
        {
            if(arr[i] + carry == 2){
                arr[i] = 0;
                carry = 1;
            }
            else if(arr[i] == 0 && carry == 1){
                arr[i] = 1;
                carry = 0;
            }
        }
        while(true){
            countzeroes = 0;
            
            for (long long int i = 0; i < strL.size(); ++i)
            {
                if(arr[i] == 1 && arr1[i] == 1){
                    arr[i] = 1;
                    arr1[i] = 1;
                }
                else{
                    arr[i] = 0;
                    arr1[i] = 0;
                    countzeroes++;
                } 
                
            }
            
            if(countzeroes == strL.size())
                break;            
 
           
            carry = -1;
            int boom = 0;
            for (long long int i = strL.size()-1; i >= 0; i--)
            {
                if(arr[i] + carry < 0){
                    arr[i] = 1;
                    carry = 0;
                }
                else if(arr[i] + carry == 0 && carry == -1){
                    arr[i] = 0;
                    carry = 0;
                    break;
                }
                else if(arr[i] == 1 && boom == 0){
                    arr[i] = 1 - arr[i];
                    break;
                }
                else{
                    arr[i] = 1 - arr[i];
                }
                
            }
       
            count++;
            
        }
        cout<<count+1<<endl;
    }
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
} 
