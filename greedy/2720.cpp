// 세탁소 사장 동혁

#include <iostream>
using namespace std;

//enum coin {QUAR = 25, DIME = 10, NICK = 5, PENN = 1};
const int coin[4] = {25, 10, 5, 1};

int main(void)
{
    int T = 0;
    int num_quar = 0;
    int num_dime = 0;
    int num_nick = 0;
    int num_penn = 0;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int C = 0;
        cin >> C;

        num_quar = C / coin[0];
        C = C % coin[0];
        num_dime = C / coin[1];
        C = C % coin[1];
        num_nick = C / coin[2];
        C = C % coin[2];
        num_penn = C;
        
        cout << num_quar << ' ' << num_dime << ' ' << num_nick << ' ' << num_penn << '\n';
    }

    return 0;
}