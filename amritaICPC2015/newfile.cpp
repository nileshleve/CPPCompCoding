#include <iostream>
#include <limits>
#include <stdexcept>


using namespace std;
void MyFunc(char c)
{
if(c < numeric_limits<char>::max() )
	return invalid_argument;
}

int main(){
	try{
		MyFunc(256);
	}
	catch(invalid_argument& e){
		cerr << e.what() <<endl;
		return -1;
	}
	return 0;
}
