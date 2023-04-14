#pragma warning(disable:4786)
#include <set>
#include <iostream>
//#if _MSC_VER > 1020   // if VC++ version is > 4.2
using namespace std;  // std c++ libs implemented in std
//#endif
typedef set <int, less <int> , allocator <int> > SET_INT;

void truefalse(int x)
{
  cout << (x?"True":"False") << endl;
}
int main()
{
  SET_INT s1;
  cout << "s1.insert(5)" << endl;
  s1.insert(5);
  cout << "s1.insert(8)" << endl;
  s1.insert(8);
  cout << "s1.insert(12)" << endl;
  s1.insert(12);

  SET_INT::iterator it;
  cout << "it=find(8)" << endl;
  it=s1.find(8);
  cout << "it!=s1.end() returned ";
  truefalse(it!=s1.end());  //  True

  cout << "it=find(6)" << endl;
  it=s1.find(6);
  cout << "it!=s1.end() returned ";
  truefalse(it!=s1.end());  // False

  cout << "it==s1.end() returned ";
  truefalse(it==s1.end());  // True

  cout << endl;
  cout << "it=find(5)" << endl;
  it=s1.find(8);
  cout << "it==s1.end() returned ";
  truefalse(it==s1.end());  // False
  cout << "it!=s1.end() returned ";
  truefalse(it!=s1.end());  // True

  set <int>::iterator itt;
  return 0;
}