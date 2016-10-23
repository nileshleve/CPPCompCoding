#include <iostream>

#include <typeinfo>

using namespace std;
class A{
};
int main(){
	char c;
	float x;
	if(typeid(c) != typeid(x))
	cout << typeid(c).name() <<endl;
	cout << typeid(A).name();
	return 0;
}
