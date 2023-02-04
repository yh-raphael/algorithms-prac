#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio (0);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A, B; cin >> A >> B;
        
        long tail = 1;
        for (int j = 0; j < B; j++)
        {
            tail *= A;
            tail %= 10; // cout << tail << ' ';
        }
        if (tail == 0)
            cout << 10 << '\n';
        else
            cout << tail << '\n';
    }
    return 0;
}