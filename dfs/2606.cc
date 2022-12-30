// Written by Raphael on 2022-12-30-Fri.
#include <iostream>
#include <vector>       // vector <int>, result_dfs.push_back ();
#include <algorithm>    // sort (node[i].begin(), node[i].end());
#include <cstring>      // memset (check, false, sizeof(check) / sizeof(bool));

using namespace std;

vector <int> node[101];
vector <int> result_dfs;
bool check[101];

void dfs (int x)
{
    // Check the visit.
    check[x] = true;
    result_dfs.push_back (x);

    // Recursively traverse - num of iteration: num of node elements.
    for (unsigned int i = 0; i < node[x].size (); i++)
    {
        if (!check[node[x][i]])
        {
            dfs (node[x][i]);
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    int NC, NE, A, B;      // num of computers, num of Edges.
    cin >> NC;
    cin >> NE;

    // num of iteration: NE.
    for (int i = 0; i < NE; i++)
    {
        cin >> A >> B;
        node[A].push_back (B);  // bidirectional.
        node[B].push_back (A);  // bidirectional.
    }

    // iteration: 1 ~ NE.
    // for (int i = 1; i <= NE; i++)
    // {
    //     sort (node[i].begin(), node[i].end());
    // }

    memset (check, false, sizeof(check) / sizeof(bool));
    dfs (1);

    // validate!
    // for (unsigned int i = 0; i < result_dfs.size (); i++)
    //     cout << result_dfs[i] << ' ';
    // cout << '\n';

    cout << result_dfs.size () - 1 << '\n';

    return 0;
}