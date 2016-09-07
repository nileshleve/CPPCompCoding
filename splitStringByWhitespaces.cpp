#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str("Split me by whitespaces");
    string buf; // Have a buffer string
    stringstream ss(str); // Insert the string into a stream

    vector<string> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);
}


/* Something Complementary



string s="12345";
int x=0;
stringstream convert(s);//object from the class stringstream.
convert>>x; //the object has the value 12345 and stream it to the integer x.
//now the variable x holds the value 12345.

*/