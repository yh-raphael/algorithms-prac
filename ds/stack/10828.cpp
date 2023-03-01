#include <iostream>
#include <stack>        // stack <int> stk, stk.push(X), stk.empty(), stk.top(), stk.size(), stk.pop();
#include <string>       // string opcode, cin >> opcode;
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL), cout.tie (NULL);

    stack <int> stk;
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        string opcode; cin >> opcode;
        if (opcode == "push") {
            int X; cin >> X;
            stk.push (X);
        }
        else if (opcode == "pop") {
            if (stk.empty () == true) {
                cout << "-1" << '\n';
            }
            else {
                cout << stk.top () << '\n';
                stk.pop ();
            }
        }
        else if (opcode == "size") {
            cout << stk.size () << '\n';
        }
        else if (opcode == "empty") {
            if (stk.empty () == true) {
                cout << "1" << '\n';
            }
            else {
                cout << "0" << '\n';
            }
        }
        else if (opcode == "top") {
            if (stk.empty () == true) {
                cout << "-1" << '\n';
            }
            else {
                cout << stk.top () << '\n';
            }
        }
    }
    return 0;
}