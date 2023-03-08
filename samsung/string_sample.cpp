#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int main (void)
{
    string gear;
    cin >> gear;

    cout << gear << '\n';

    deque <int> dq;

    dq.push_back (1);
    dq.push_back (2);
    dq.push_back (3);

    dq.push_front (7);
    dq.push_front (8);
    dq.push_front (9);

    cout << dq.size () << '\n';
    for (unsigned int i = 0; i < dq.size (); i++)
        cout << dq[i] << ' ';
    cout << '\n';




    int tmp = dq.front ();
    dq.pop_front ();
    for (unsigned int i = 0; i < dq.size (); i++)
        cout << dq[i] << ' ';
    cout << '\n';

    dq.push_back (tmp);
    for (unsigned int i = 0; i < dq.size (); i++)
        cout << dq[i] << ' ';
    cout << '\n';



    tmp = dq.back ();
    dq.pop_back ();
    for (unsigned int i = 0; i < dq.size (); i++)
        cout << dq[i] << ' ';
    cout << '\n';

    dq.push_front (tmp);
    for (unsigned int i = 0; i < dq.size (); i++)
        cout << dq[i] << ' ';
    cout << '\n';

    return 0;
}