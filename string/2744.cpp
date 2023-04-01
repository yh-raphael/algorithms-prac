#include <iostream>
#include <cstring>
using namespace std;
int main (void)
{
    int a = 'a' - 'A';
    string str_in; cin >> str_in;
    for (unsigned int i = 0; i < str_in.size (); i++) {
        if (str_in[i] >= 'A' && str_in[i] <= 'Z') {
            str_in[i] = str_in[i] + a;
        }
        else {
            str_in[i] = str_in[i] - a;
        }
    }
    cout << str_in << endl;
    return 0;
}