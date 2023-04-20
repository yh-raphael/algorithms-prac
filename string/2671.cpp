#include <iostream>
#include <cstring>
using namespace std;

string str;

bool solve (void)
{
    int cur = 0;
    int slen = str.length (); //cout << "slen: " << slen << endl; cout << str[1] << endl;
    while (cur < slen)
    {
        if (str[cur] == '0') {
            if (cur+1 == slen) return false;
            if (str[cur+1] != '1') return false;
            cur += 2;   // 두 칸 jump
        }
        else {
            if (cur+3 >= slen) return false;
            if (str[cur+1] != '0' || str[cur+2] != '0') return false;
            cur ++;
            while (cur < slen && str[cur] == '0')
                cur ++;
            if (cur >= slen) return false;
            cur ++;
            while (cur < slen && str[cur] == '1') {
                if (cur+2 < slen && str[cur+1] == '0' && str[cur+2] == '0') break;
                cur ++;
            }
        }
    }
    return true;
}

int main (void)
{
    cin >> str;
    
    bool flag = solve ();
    if (flag)
        cout << "SUBMARINE" << '\n';
    else
        cout << "NOISE" << '\n';
    return 0;
}