// Written by Raphael on 2023-01-16-Mon.
#include <iostream>
#include <vector>           // vector <int> node[101];
#include <algorithm>        // sort (node[i].begin (), node[i].end ());
#include <queue>            // queue <int> Q; Q.push(), Q.front(), Q.pop(), Q.empty();

using namespace std;

vector <int> node[101];
bool isVisited[101] = { false, };

int result = 0;

void bfs (int start)
{
    queue <int> Q;
    Q.push (start);
    isVisited[start] = true;

    while (!Q.empty ())
    {
        int cur = Q.front ();
        Q.pop ();

        for (unsigned int i = 0; i < node[cur].size (); i++)
        {
            if (isVisited[node[cur][i]] == false) {
                Q.push (node[cur][i]);
                isVisited[node[cur][i]] = true;
                result ++;
            }
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (NULL); cout.tie (NULL);

    int NC; cin >> NC;      // Number of Computers.
    int NE; cin >> NE;      // Number of Edges.
    for (int i = 1; i <= NE; i++)
    {
        int a, b; cin >> a >> b;
        node[a].push_back (b);
        node[b].push_back (a);
    }

    for (int i = 1; i <= NC; i++)
    {
        sort (node[i].begin (), node[i].end ());
    }

    bfs (1);

    cout << result << '\n';
    return 0;
}