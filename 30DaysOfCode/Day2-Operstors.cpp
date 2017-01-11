	#include <bits/stdc++.h>
	using namespace std;
	int main(int argc, char const *argv[])
	{
		double mealCost;
		cin>>mealCost;
		int tipPercent;
		cin>>tipPercent;
		int taxPercent;
		cin>>taxPercent;
		double tip, tax;
		tip = mealCost * tipPercent * .01;
		tax = mealCost * taxPercent * .01;
		float totalCost = mealCost + tip + tax;
		int tc = floor(totalCost + 0.5);
		cout<<"The total meal cost is "<<tc<<" "<<"dollars."<<endl;
		return 0;
	}