#include <iostream>
#include <vector>       // vector <int> v[101];
#include <algorithm>    // sort (v[i].begin(), v[i].end())
#include <queue>        // queue <int> q;

using namespace std;
vector <int> v[101];
bool isVisited[101];

int result = -1;

queue <int> q;
int isVisited_2[101];

void bfs (int x, int y)
{
    q.push (x);
    isVisited_2[x] = 0;

    while (!q.empty ())
    {
        int cur = q.front ();
        q.pop ();

        for (unsigned int i = 0; i < v[cur].size (); i++)
        {
            if (!isVisited_2[v[cur][i]] && v[cur][i] != x) {
                q.push (v[cur][i]);
                isVisited_2[v[cur][i]] = isVisited_2[cur] + 1;
                // cout << v[cur][i] << ' ' << isVisited_2[v[cur][i]] << '\n';
            }

            // if it's the answer!
            if (v[cur][i] == y) {
                result = isVisited_2[v[cur][i]];
            }
        }
    }
}

void dfs (int x, int y, int cnt)
{
    isVisited[x] = true;
    if (x == y) {
        result = cnt;
    }

    for (unsigned int i = 0; i < v[x].size (); i++)
    {
        if (!isVisited[v[x][i]]) {
            dfs (v[x][i], y, cnt + 1);
        }
    }
}

int main (void)
{
    int N; cin >> N;
    int x, y; cin >> x >> y;
    int M; cin >> M;

    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back (b);     // Bidirectional relationship.
        v[b].push_back (a);     // Bidirectional relationship.
    }

    for (int i = 1; i <= N; i++)
    {
        sort (v[i].begin (), v[i].end ());
    }

    // dfs (x, y, 0);
    bfs (x, y);

    cout << result << '\n';
    return 0;
}