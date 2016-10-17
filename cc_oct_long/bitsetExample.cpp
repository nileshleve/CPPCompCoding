/* Example 01: Bitset
Explains the usage std::bitset
*/
 
#include <iostream>
#include <bitset>
//#include <conio.h>
 
using namespace std;
 
int main()
{
    //Constuct 01: 8 bits initialized to zero
    bitset<8> bitset1;
    cout << "Construction without any parameter. Content of bitset1 :"
        << bitset1 << endl;
 
    //Construct 02: Construct it from an integer number
    bitset<8> bitset2(177);
    cout << "Constructor with int as parameter. Content of bitset2: "
        << bitset2 << endl;
 
    //Construct 03: Construct it from string 
    bitset<8> bitset3(string("11111100"));
    cout << "Constructor with string parameter.Content of bitset3: "
        << bitset3 << endl;
 
    //Usage 01: Set and Reset a bit in the bitset
    bitset2.reset(); cout << bitset2 << endl;
    bitset2.set(4); cout << bitset2 << endl;
    bitset2.set(7); cout << bitset2 << endl;
 
    bitset3.set();  cout << bitset3 << endl;
    bitset3.reset(1); cout << bitset3 << endl;
    bitset3.reset(2); cout << bitset3 << endl;
 
    //Usage 02: Testing a perticular Bit
    cout << "Bitset3: " << bitset3 << endl;
    for (int i=0; i<bitset3.size(); i++)
    {
        if (bitset3.test(i))
            cout << "Bit " << i << " is Set" << endl;
        else
            cout << "Bit " << i << " is Not Set" << endl;
    }
 
    //Usage 03: Number of bits set
    bitset3.reset();
    bitset3.set(2);
    bitset3.set(4);
    bitset3.set(5);
    cout << bitset3.count() << " Bit(s) set" << endl;
    //getch();
    return 0;
}