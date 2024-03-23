#include <iostream>
#include <queue>
#include <climits>
using namespace std;
 
#define MAXN (100+2)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int force[MAXN][MAXN];    // 해당 좌표까지 도달할 수 있는 방법 중, 최소 힘 기록.
 
struct node {
    int r,c,f;  // row, column, force.
};
queue<struct node> Q;
 
void Init()
{
    for (int i=0; i<=N+1; i++) {
        for (int j=0; j<=N+1; j++) {
            force[i][j] = INT_MAX;      // min값으로 계속 갱신하면 됨.
        }
    }
}
int AddedForce(int cr, int cc, int nr, int nc)
{
    int start = map[cr][cc];
    int end = map[nr][nc];
    if (start == end) {
        return 0;
    }
    else if (start > end) {
        return start - end;
    }
    else if (start < end) {
        return (end - start) * (end - start);
    }
    return -100;    // 있을 수 없지만 warning 제거용..
}
int DoBFS()
{
    int dr[] = {0,1,0,-1};
    int dc[] = {1,0,-1,0};
 
    force[0][0] = 0;
    Q.push({0, 0, 0});  // (0,0)에서만 시작하면 됨. 현재 route가 최소가 아니면 pruning.
    while (!Q.empty()) {
        int cur_r = Q.front().r;
        int cur_c = Q.front().c;
        int cur_f = Q.front().f;
        Q.pop();
 
        //cout << "cur_r: " << cur_r << ", cur_c: " << cur_c << ", cur_f: " << cur_f << endl;
        if (cur_r == eh && cur_c == ew) continue;       // 목적지 도달하면 pop만!
 
        // 사방 조사.
        for (int i=0; i<4; i++) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            if (next_r < 0 || next_r > N+1 || next_c < 0 || next_c > N+1) continue;     // out of boundary.
            int next_f = cur_f + AddedForce(cur_r, cur_c, next_r, next_c);
            //cout << "next_f: " << next_f << endl;
 
            // 갱신해야되는 상황.
            if (next_f < force[next_r][next_c]) {
                force[next_r][next_c] = next_f;
                Q.push({next_r, next_c, next_f});   //cout << "--- push! ---" << endl;
            }
            // pruning해야 하는 상황.
            else {
                continue;
            }
        }        
    }
    return force[eh][ew];
}
int Solve()
{
    int sol = -2;
    Init();
    sol = DoBFS();
    return sol;
}
 
void InputData(){
    cin >> N;
    cin >> eh >> ew;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cin >> map[h][w];
        }
    }
}
int main(){
    int ans = -1;
    InputData();//입력 받는 부분
 
    //여기서부터 작성
    ans = Solve();
 
    cout << ans << endl;//출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1178
    Language: C++
    Result: Accepted
    Time:165 ms
    Memory:2700 kb
****************************************************************/