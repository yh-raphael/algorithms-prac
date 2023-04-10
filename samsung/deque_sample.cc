#include <iostream>
#include <deque>
using namespace std;

int main (void)
{
    deque <int> DQ;
    cout << DQ.size() << endl;
    cout << DQ.empty() << endl;
    cout << DQ.front() << endl;
    return 0;
}