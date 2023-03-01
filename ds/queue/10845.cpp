#include <iostream>
#include <queue>        // queue <int> Q, Q.push (X), Q.empty (), Q.size(), Q.pop (), Q.front (), Q.back ()
#include <string>       // string opcode
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);

    queue <int> Q;
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        string opcode; cin >> opcode;
        if (opcode == "push") {
            int X; cin >> X;
            Q.push (X);
        }
        else if (opcode == "pop") {
            if (Q.empty () == true)
                cout << "-1" << '\n';
            else {
                cout << Q.front () << '\n';
                Q.pop ();
            }
        }
        else if (opcode == "size") {
            cout << Q.size () << '\n';
        }
        else if (opcode == "empty") {
            cout << Q.empty () << '\n';
        }
        else if (opcode == "front") {
            if (Q.empty () == true)
                cout << "-1" << '\n';
            else
                cout << Q.front () << '\n';
        }
        else if (opcode == "back") {
            if (Q.empty () == true)
                cout << "-1" << '\n';
            else
                cout << Q.back () << '\n';
        }
    }
    return 0;
}