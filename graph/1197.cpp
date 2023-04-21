#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector <pair <int , pair <int, int> > > vec;
int Parent[10001] = { 0,};
int result = 0;

int Find (int x)
{
    if (Parent[x] == x) return x;
    else {
        Parent[x] = Find (Parent[x]);
    }
    return Parent[x];
}

void Union (int x, int y)
{
    x = Find (x);
    y = Find (y);

    if (x != y) Parent[y] = x;
}

bool SameParent (int x, int y)
{
    x = Find (x);
    y = Find (y);

    if (x == y)
        return true;
    else
        return false;
}

int main (void)
{
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int F, T, C;
        cin >> F >> T >> C;
        vec.push_back (make_pair (C, make_pair (F, T)));
    }
    // sort w.r.t. Cost.
    sort (vec.begin (), vec.end ());

    // Kruskal's algorithm start //
    // init Parent array.
    for (int i = 0; i <= V; i++) {
        Parent[i] = i;
    }
    for (int i = 0; i < E; i++) {
        if (SameParent (vec[i].second.first, vec[i].second.second) == false) {
            Union (vec[i].second.first, vec[i].second.second);
            result += vec[i].first;
        }
    }
    // Kruskal's algorithm end //

    cout << result << endl;
    return 0;
}