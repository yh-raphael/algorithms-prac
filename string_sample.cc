#include <iostream>
#include <cstring>
using namespace std;

int main (void)
{
    string t;
    t = "helloworld";
    cout << t << endl;

    string tmp = "";
    cout << tmp << endl;
    tmp += t[0];
    cout << tmp << endl;
    tmp += t[1];
    cout << tmp << endl;
    tmp += t[2];
    cout << tmp << endl;
    return 0;
}