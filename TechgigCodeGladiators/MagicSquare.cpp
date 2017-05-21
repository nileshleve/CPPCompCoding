#include <bits/stdc++.h>

using namespace std;

int checkrotation(int checkarr[], int checkarr1[], int srn){
	
	cout<<"checkrotation called \n";
	int notedpos = 0;
	for (int i = 0; i < srn; ++i)
	{
		if(checkarr[i] != 0){
			for (int j = 0; j < srn; ++j)
			{
				if(checkarr[i] == checkarr1[j]){
					notedpos = j;
					while(i < srn && j < srn){
						if((checkarr[i] == checkarr1[j]) || checkarr[i] == 0 || checkarr1[j] == 0){
							i++;
							j++;
							continue;
						}
						else{
							return 0;
						}
					}
					j = 0;
					while(i < srn && j < notedpos){
						if((checkarr[i] == checkarr1[j]) || checkarr[i] == 0 || checkarr1[j] == 0){
							i++;
							j++;
							continue;
						}
						else{
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;

}

int check(int arr[][20], int srn){
	cout<<"check called\n";
	for (int i = 0; i < srn; ++i)
	{
		for (int j = 0; j < srn; ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	int checkarr[srn];
	int checkarr1[srn];
	int k = 0;
	for (int j = 0; j < srn; ++j)
	{
		checkarr[k++] = arr[0][j];
	}
	k = 0;
	for (int i = 1; i < srn; ++i)
	{
		for (int j = 0; j < srn; ++j)
		{
			checkarr1[k++] = arr[i][j];
		}
		if(!checkrotation(checkarr, checkarr1, srn)){
			return 0;
		}
		for (int j = 0; j < srn; ++j)
		{
			checkarr[j] = checkarr1[j];
		}
		k = 0;
	}
	return 1;

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cin>>n;
	int srn = sqrt(n);
	int a[n][400];
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>a[i][j];
		}
	}
	if(a[0][0] == 0)
		a[0][0] = 1;
	if(a[0][0] > 1){
		cout<<0;
		return 0;
	}
	int arr[srn][20];
	int p = 0;
	int ctr1 = 0;
	int ctr2 = 0;
	for (int k = 0; k < srn; ++k)
	{
		p = 0;
		while(p < srn){
			for (int i = p; i < n; i = i + srn)
			{
				for (int j = k * srn; j < (k + 1) * srn ; ++j)
				{
					arr[ctr1][ctr2++] = a[i][j];
				}
				ctr1++;
				ctr2 = 0;
			}
			if(!check(arr, srn)){
				ans = 0;
				break;
			}
			p++;	
		}
	}
	cout<<ans<<endl;
	return 0;
}