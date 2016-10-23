#include <iostream>
using namespace std;

void Division(const double a, const double b);
int main(){
	double op1=0, op2=10;
	try{
		Division(op1,op2);
	}
	catch(const char* Str){
		cout<<"\nBad Operator: "<<Str;
	}
	return 0;
}

void Division(const double a, const double b){
	double res;
	if(b == 0)
		throw "Division not allowed";
	res = a/b;
	cout<<res;
}