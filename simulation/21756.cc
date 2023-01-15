#include <iostream>
#include <vector>

using namespace std;
vector <int> v1, v2;

int main (void)
{
    int N; cin >> N;

    int arr [101];

    for (int i = 0; i <= N; i++)
    {
        v1.push_back (i);
    }

    while (v1.size () != 2)
    {
        v2.clear ();
        v2.push_back (0);
        for (int i = 2; i < v1.size (); i += 2)
        {
            v2.push_back (v1[i]);
        }
        v1 = v2;
    }
    cout << v1[1] << '\n';

    return 0;
}