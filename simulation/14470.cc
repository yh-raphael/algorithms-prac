#include <iostream>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    int A,B,C,D,E;
    cin >> A>>B>>C>>D>>E;    // A:고기 온도,B:고기 최종온도

    if (A < 0)
        cout << (-1) * A * C + D + B*E << '\n';
    else if (A == 0)
        cout <<  D + B*E << '\n';
    else
        cout << (B-A) *E << '\n';
    return 0;
}