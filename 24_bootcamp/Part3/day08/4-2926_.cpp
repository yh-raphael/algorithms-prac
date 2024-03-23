#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAXN (50)
 
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];
 
int S_r, S_c;
struct node{
    int r, c;
    int rank;
};
queue<struct node> Q_S;
int visited[MAXN+10][MAXN+10];
vector<queue<struct node>> V;
 
void PrintMap()
{
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
 
void SearchStartPos()
{
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (map[i][j] == 'S') {
                S_r = i; S_c = j;
                struct node tmp_node = {S_r, S_c, 0};
                Q_S.push(tmp_node); visited[S_r][S_c] = 1;
            }
            else if (map[i][j] == '*') {
                struct node tmp_node = {i, j, 0};
                queue<struct node> tmp_Q; tmp_Q.push(tmp_node);
                V.push_back(tmp_Q);
            }
        }
    }
}
int DoBFS()
{
    int dr[] = {0,1,0,-1};
    int dc[] = {1,0,-1,0};
    // 두 개의 BFS를 동일한 시간 축 cur_time으로 관리.
    for (int cur_time = 0; ; cur_time ++) {
        //1. 홍수 BFS: 각 홍수 지점에 대해서.
        for (int i=0; i<V.size(); i++) {
            while (!V[i].empty()) {
                // 큐에 들어 있으면 계속!
                int cur_r = V[i].front().r;
                int cur_c = V[i].front().c;
                int cur_rank = V[i].front().rank;
                if (cur_time < cur_rank) break;
 
                // 사방에 대해서.
                for (int j=0; j<4; j++) {
                    int next_r = cur_r + dr[j];
                    int next_c = cur_c + dc[j];
                    int next_rank = cur_rank + 1;
 
                    if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
                    if (map[next_r][next_c] == '*') continue;
                    if (map[next_r][next_c] == 'X') continue;
                    if (map[next_r][next_c] == 'D') continue;
 
                    map[next_r][next_c] = '*';
                    V[i].push({next_r, next_c, next_rank});
                }
                V[i].pop();
            }
        }
        //2. 화가 BFS.
        while (!Q_S.empty()) {
            int cur_r = Q_S.front().r;
            int cur_c = Q_S.front().c;
            int cur_rank = Q_S.front().rank;
            if (cur_time < cur_rank) break;
 
            // PrintMap();
            // cout << "cur_r: " << cur_r << ", cur_c: " << cur_c << ", cur_rank: " << cur_rank << endl;
            //사방에 대해서.
            for (int j=0; j<4; j++) {
                int next_r = cur_r + dr[j];
                int next_c = cur_c + dc[j];
                int next_rank = cur_rank + 1;
 
                if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
                if (visited[next_r][next_c] == 1) continue;
                if (map[next_r][next_c] == '*') continue;
                if (map[next_r][next_c] == 'X') continue;
 
                if (map[next_r][next_c] == 'D') return next_rank;       // 탈출!
                 
                Q_S.push({next_r, next_c, next_rank}); visited[next_r][next_c] = 1;
            }
            Q_S.pop();
        }
        //3. 더 갈 곳이 없어서 다 pop 되면.. die!
        if (Q_S.empty()) {
            break;
        }
    }
    return -1;
}
int Solve()
{
    int sol = 0;
    SearchStartPos();
    sol = DoBFS();
    return sol;
}
 
void Init()
{
    memset(map, 0, sizeof(map));
    Q_S = {};
    memset(visited, 0, sizeof(visited));
    V = {};
}
void InputData(){
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> map[i];
    }
}
int main(){
    int T, ans = -1;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        Init();
        InputData();//입력 받는 부분
        // 여기서부터 작성
        ans = Solve();
        if (ans == -1) cout << "KAKTUS" << endl;//출력 하는 부분
        else cout << ans << endl;
    }
    return 0;
}
/**************************************************************
    Problem: 2926
    Language: C++
    Result: Accepted
    Time:24 ms
    Memory:5016 kb
****************************************************************/