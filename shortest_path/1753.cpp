#include <iostream>
#include <vector>       // vector <pair <int, int> > Vertex[20001].
#include <utility>      // make_pair (v, w).
#include <climits>      // INT_MAX.
#include <queue>        // priority_queue <pair <int, int> > PQ.
using namespace std;

int V, E, K;
int Dist[20001] = { 0, };
vector <pair <int, int> > Vertex[20001];

int main (void)
{
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        Vertex[u].push_back (make_pair (v, w));
    }
    for (int i = 1; i <= V; i++)
        Dist[i] = INT_MAX;

    // do the Dijkstra's algorithm.
    priority_queue <pair <int, int> > PQ;           // n_cost, dst vertex #
    Dist[K] = 0;
    PQ.push (make_pair (-Dist[K], K));             // n_cost, vertex # (sort criteria -> bigger one is front)

    while (PQ.empty () == false)
    {
        int cost = -PQ.top ().first;    //cout << "cost: " << cost << endl;        // n_cost
        int cur = PQ.top ().second;     //cout << "cur:  " << cur << endl;        // vertex #
        PQ. pop ();

        // for each connected vertex.
        for (unsigned int i = 0; i < Vertex[cur].size (); i++)
        {
            int n_cost = Vertex[cur][i].second;     // cost of that conection.
            int next = Vertex[cur][i].first;        // connected vertex #.

            if (Dist[next] > cost + n_cost) {       // If this time Distance is the smallest!,
                Dist[next] = cost + n_cost;         // UPDATE Distance!
                PQ.push (make_pair (-Dist[next], next));
            }
        }
    }

    // print the result.
    for (int i = 1; i <= V; i++) {
        if (Dist[i] == INT_MAX)
            cout << "INF"<< '\n';
        else
            cout << Dist[i] << '\n';
    }

    return 0;
}