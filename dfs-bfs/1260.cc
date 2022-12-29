// Written by Raphael on Dec 30, 2022.
#include <iostream>
#include <vector>       // result_dfs.push_back()
#include <algorithm>    // sort (vec[i].begin(), vec[i].end())
#include <cstring>      // memset (check, false, sizeof(check))
#include <queue>        // q.empty(), q.front() // q.pop(), q.push(vec[x][i])
using namespace std;

vector <int> vec[10001];
vector <int> result_bfs;
vector <int> result_dfs;
bool check[1001];

// Queue.
void bfs (int temp)
{
    queue <int> q;
    q.push (temp);
    check[temp] = true;

    while (!q.empty ())
    {
        int x = q.front ();
        q.pop ();
        result_bfs.push_back (x);

        for (unsigned long i = 0; i < vec[x].size(); i++)
        {
            if (!check[vec[x][i]]) {
                q.push (vec[x][i]);
                check[vec[x][i]] = true;
            }
        }
    }
}

// Recursive.
void dfs (int x)
{
    check[x] = true;
    result_dfs.push_back (x);

    for (unsigned long i = 0; i < vec[x].size(); i++)
    {
        if (!check[vec[x][i]])
            dfs(vec[x][i]);
    }
}

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    int N, M, V, A, B;
    cin >> N >> M >> V;

    // Max num of edges: M
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        vec[A].push_back (B);   // bidirectional.
        vec[B].push_back (A);   // bidirectional.
    }
    // for each N vectors(nodes).
    for (int i = 1; i <= N; i++)
    {
        sort (vec[i].begin(), vec[i].end());    // <algorithm>
    }
    
    //memset (check, false, sizeof(check));   //  init.
    dfs (V);
    
    memset (check, false, sizeof(check));   //  reinit.
    bfs (V);

    // print.
    for (unsigned int i = 0; i < result_dfs.size(); i++)
        cout << result_dfs[i] << ' ';
    cout << '\n';

    for (unsigned int i = 0; i < result_bfs.size(); i++)
        cout << result_bfs[i] << ' ';
    cout << '\n';

    return 0;
}