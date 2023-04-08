#include <iostream>
#include <cstring>      // memset ().
#include <queue>        // BFS.
#include <utility>      // make_pair ().
#include <climits>      // INT_MAX.
using namespace std;

typedef struct _person {
    int r;
    int c;
    int gr;
    int gc;
} Person;

int N, M;
int map[20][20];    // 1: BaseCamp, 0: blank, -1: 이미 도착 (못지나감)
Person P[31];
int dist[20][20];   // for BFS.

void print_map ()
{
    cout << endl << "map" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void print_person ()
{
    cout << endl << "person" << endl;
    for (int i = 1; i <= M; i++) {
        cout << "(" << P[i].r  << ", " << P[i].c  << ")" << ", ";
        cout << "(" << P[i].gr << ", " << P[i].gc << ")" << endl;
    }
}

void print_dist ()
{
    cout << endl << "dist" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INT_MAX) cout << "x" << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
}

void input (void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> P[i].gr >> P[i].gc;
    }
}

bool isArrived (Person a)
{
    return (a.r == a.gr && a.c == a.gc);
}

bool isFinished (void)
{
    for (int i = 1; i <= M; i++) {
        if (isArrived (P[i]) == false) return false;
    }
    return true;
}

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
void do_bfs (int gr, int gc)
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    queue <pair <int, int> > Q;
    Q.push (make_pair (gr, gc));
    dist[gr][gc] = 0;

    while (Q.empty () == false)
    {
        int r = Q.front ().first;
        int c = Q.front ().second;
        Q.pop ();

        for (int i = 0; i < 4; i++) {   // 모든 방향에 대해서.
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if (map[nr][nc] == -1) continue;
            if (dist[nr][nc] != INT_MAX) continue;

            Q.push (make_pair (nr, nc));
            dist[nr][nc] = dist[r][c] + 1;
        }
    }
}

void init_person (int t)
{
    do_bfs (P[t].gr, P[t].gc);
    //print_dist ();

    int min_val = INT_MAX;
    int min_r = 0;
    int min_c = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != 1) continue;
            
            if (dist[i][j] < min_val) {
                min_val = dist[i][j];
                min_r = i;
                min_c = j;
            }
        }
    }

    P[t].r = min_r;
    P[t].c = min_c;
    map[min_r][min_c] = -1;
    //print_person ();
}

void move_person (int idx)
{
    do_bfs (P[idx].gr, P[idx].gc);
    //print_dist ();
    
    int min_val = INT_MAX;
    int min_r = 0;
    int min_c = 0;
    for (int i = 0; i < 4; i++) {   // 모든 인접 4 방향에 대해서.
        int nr = P[idx].r + dr[i];
        int nc = P[idx].c + dc[i];
        if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
        
        if (dist[nr][nc] < min_val) {
            min_val = dist[nr][nc];
            min_r = nr;
            min_c = nc;
        }
    }

    P[idx].r = min_r;   //cout << min_r << endl;
    P[idx].c = min_c;   //cout << min_c << endl;
}

void check_arrival (int idx)
{
    if (isArrived (P[idx])) {
        map[P[idx].r][P[idx].c] = -1;
    }
}

void do_simulation (void)
{
    int clk = 0;
    while (isFinished () == false)
    {
        clk ++;
        // 1. move person
        for (int i = 1; i < clk && i <= M; i++) {
            if (isArrived (P[i]) == false) {
                move_person (i); //cout << "i: " << i << endl;
            }
        }

        // 2. check arrival
        for (int i = 1; i < clk; i++) {
            check_arrival (i);
        }

        // 3. init person
        if (clk <= M) {
            init_person (clk);
        }
        // cout << endl << "-- clk --: " << clk << endl;
        // print_map ();
        // print_person ();
    }
    cout << clk << '\n';
}

int main (void)
{
    input ();
    //print_map ();
    do_simulation ();

    return 0;
}