#include <iostream>
#include <vector>       // vector <int> node[1001]
#include <algorithm>    // sort (node[i].begin (), node[i].end (), cmp)
using namespace std;

int N, M;
vector <int> node[1001];        // an array of <int> vector.
bool check[1001] = { false, };
int result = 0;

// sorting criterion.
bool cmp (int a, int b)
{
    if (a >= b)
        return true;
    else
        return false;
}

void dfs (int x)
{
    for (unsigned int i = 0; i < node[x].size (); i++)
    {
        if (check[node[x][i]] == false) {
            check[node[x][i]] = true; //cout << node[x][i] << ' ';
            dfs (node[x][i]);
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);
    cin >> N >> M;
    int a, b;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        node[a].push_back (b);
        node[b].push_back (a);
    }
    
    // sort.
    for (int i = 1; i <= N; i++)
        sort (node[i].begin (), node[i].end ());

    // do dfs.
    for (int i = 1; i <= N; i++)
    {
        if (check[i] == false) {
            check[i] = true; //cout << i << ' ';
            dfs (i);
            result ++;
        }
    }

    cout << result << '\n';
    return 0;
}

    // cout << endl << N << ' ' << M << endl << endl;
    // for (int i = 1; i <= N; i++) {
    //     cout << i << ": ";
    //     for (unsigned int j = 0; j < node[i].size (); j++) {
    //         cout << node[i][j] << ' ';
    //     }
    //     cout << endl;
    // }