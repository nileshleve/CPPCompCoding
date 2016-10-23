#include <iostream>
using namespace std;
class Testpm
{
public:
void m_func1()
{
cout << func1()
{
cout << "func1\n";
}
int m_num;
};
void (Testpm :: *pmfn)()=&Testpm :: m_func1;
int Testpm:: *pmd=&testpm :: m_num;
int main()
{
Testpm ATestpm;
Testpm *ptestpm = new testpm;
(ATestpm.*pmfn)();
(pTestpm ->* pmfn)();
ATestpm.*pmd=1;
ptestpm ->*pmd=1;
pTestpm ->* pmd=2;
cout << ATestpm.*pmd << end1
<<pTestpm ->* pmd << endl;
}