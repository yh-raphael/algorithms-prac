#include <iostream>
#include <vector>

using namespace std;

int main (void)
{
    vector <int> direction;
    direction.push_back (0);
    direction.push_back (1);
    direction.push_back (2);
    direction.push_back (3);

    int s = direction.size ();
    for (int i = s - 1; i >= 0; i--)
    {
        cout << direction.at (i) << ' ';
    }
    cout << '\n';

    vector <int> tmp;
    tmp = direction;
    int ss = tmp.size (); cout << "SS size: " << ss << endl;
    for (int i = ss - 1; i >= 0; i--)
    {
        cout << tmp[i] << ' ';
    }
    cout << '\n';
    return 0;
}