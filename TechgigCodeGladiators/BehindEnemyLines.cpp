#include <bits/stdc++.h>

using namespace std;


int check(int w[], int temp[]){

	for (int i = 0; i < 60; ++i)
	{
		if(w[i] != temp[i]){
			//cout<<"checking:0"<<endl;
			return 0;
		}
	}
	//cout<<"checking:1"<<endl;

	return 1;
}

int appearanceCount(int input1,int input2,char* input3,char* input4)
    {
    	int ans = 0;
        int len1 = input1;
        int len2 = input2;
        string str1 = input3;
        string str2 = input4;
        int w[60] = {0};
        int temp[60] = {0};
        for (int i = 0; i < len1; ++i)
        {
        	w[(int)(str1[i] - 'A')]++;
        	//cout<<(int)(str1[i] - 'A')<<" ";
        }
        
        for (int i = 0; i < len1; ++i)
        {
        	temp[(int)(str2[i] - 'A')]++;
        	//cout<<(int)(str2[i] - 'A')<<" ";
        }
        int start = 0;
        int end = len1 - 1;
        if(check(w, temp))
        	ans++;
        for (int i = 0; i < len2 - len1 + 1; ++i)
        {
        	temp[(int)(str2[start++] - 'A')]--;
        	temp[(int)(str2[++end] - 'A')]++;
        	if(check(w, temp))
        		ans++;
        }
        return ans;
    }



int main() {
    int output = 0;
    int ip1;
    scanf("%d", &ip1);
    int ip2;
    scanf("%d", &ip2);
    char* ip3;
    ip3 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip3);
    char* ip4;
    ip4 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip4);
    output = appearanceCount(ip1,ip2,ip3,ip4);
    printf("%d\n", output);
    return 0;
}
