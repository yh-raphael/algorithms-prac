#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001] = {0,};

struct edge {
	int u,v,w;
};

int find(int u) {
	if(u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
    //return find (parent[u]);
}

void merge(int u, int v) { 
	u = find(u);
	v = find(v);
	// 부모들 간의 union!
	parent[v] = u;
}

int comp (struct edge a, struct edge b) {
	if (a.w < b.w) return true;
    else return false;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector <struct edge> vec;
	int V, E;
	long long ans = 0;
	cin >> V >> E;
	int A,B,C;
	
	for(int i = 0; i < E; i++) {
		cin >> A >> B >> C;
        edge tmp = {A, B, C};
		vec.push_back(tmp);
	}
    sort (vec.begin (), vec.end (), comp);

    // init parent array.
	for(int i = 1; i <= V; i++)
		parent[i] = i;
	
    // Kruskal's algorithm.
	for(int i = 0; i < E; i++) {
		if (find(vec[i].u) != find(vec[i].v)) {
			merge(vec[i].u, vec[i].v);
			ans += vec[i].w;
		}
	}
	
	cout << ans << '\n';
	return 0;
}