// Written by Raphael on 2023-02-09-Fri.
#include <iostream>
using namespace std;

int main (void)
{
    int C_1; cin >> C_1;

    int cur = C_1;
    int count = 1;
    while (1)
    {
        if (cur == 1)
            break;
        if (cur % 2 == 0) {
            cur = cur / 2;
            count ++;
        }
        else if (cur % 2 == 1){
            cur = 3 * cur + 1;
            count ++;
        }
    }

    cout << count << '\n';
    return 0;
}