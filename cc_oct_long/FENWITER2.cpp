
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t-- > 0){
        string str1, str2, str3;
        int n;
        int count = 0;
        cin>>str1>>str2>>str3;
        cin>>n;
        string strL = str1;
        for (int i = 0; i < n; ++i)
        {
            strL = strL + str2;
        }
        strL = strL + str3;
        int carry = 1;
        int countzeroes;
        vector<bool> arr;
        vector<bool> arr1;
        vector<bool> arr2;


        for (int i = 0; i < strL.size(); ++i)
        {
            arr.push_back(strL[i] - 48);
        }
        arr1 = arr2 = arr;
        int check = 1;
        while(true){
            countzeroes = 0;
            if(check == 1){
                carry = 1;
                for (int i = strL.size()-1; i >= 0; i--)
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
                check = 0;
            }
            else{
                // for (int i = 0; i < strL.size(); ++i)
                // {
                //     arr[i] = arr2[i];
                // }
                arr = arr2;
            }


            for (int i = 0; i < strL.size(); ++i)
            {
                if(arr[i] == 1 && arr1[i] == 1)
                    arr[i] = 1;
                else{
                    arr[i] = 0;
                    countzeroes++;
                } 
                
            }
            
            if(countzeroes == strL.size())
                break;


            
            // for (int i = 0; i < strL.size(); ++i)
            // {
            //     arr2[i] = arr[i];
            // }
            arr2 = arr;
            

            carry = -1;
            int boom = 0;
            for (int i = strL.size()-1; i >= 0; i--)
            {
                if(arr[i] + carry < 0){
                    arr[i] = 1;
                    carry = 0;
                }
                else if(arr[i] + carry == 0 && carry == -1){
                    arr[i] = 0;
                    carry = 0;
                }
                else if(arr[i] == 1 && boom == 0){
                    arr[i] = 1 - arr[i];
                    break;
                }
                else{
                    arr[i] = 1 - arr[i];
                }
                
            }
            
            // for (int i = 0; i < strL.size(); ++i)
            // {
            //     arr1[i] = arr[i];
            // }
            arr1 = arr;
            
            count++;
            

            
        }
        cout<<count+1<<endl;
    }
    return 0;
}