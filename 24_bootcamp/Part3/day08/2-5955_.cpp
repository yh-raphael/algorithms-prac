#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
 
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
struct STATE{
    int Rr, Rc;
    int Br, Bc;
    int cnt;
};
STATE first;
 
queue<STATE> Q;
 
void SetFirst()
{
    int cnt = 0;
    // 모든 값 초기화!
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (map[i][j] == 'R') {
                first.Rr = i; first.Rc = j;
                cnt++;
            }
            else if (map[i][j] == 'B') {
                first.Br = i; first.Bc = j;
                cnt++;
            }
            if (cnt == 2) break;    // 다 찾았으면 끝!
        }
        if (cnt == 2) break;        // 다 찾았으면 끝!
    }
    first.cnt = 0;
}
int DoBFS()
{
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
     
    SetFirst();
    STATE initial_state = first;
    Q.push(initial_state);
    while (!Q.empty()) {
        // 조회.
        STATE cur = {Q.front().Rr, Q.front().Rc, Q.front().Br, Q.front().Bc, Q.front().cnt};
        //cout << "(" << cur.Rr << ','<< cur.Rc << ") (" << cur.Br << ','<< cur.Bc << ") cnt:" << cur.cnt << endl;
        // 사방에 대하여 -> 예외 및 return 처리, push할건 push.
        for (int i=0; i<4; i++) {
            STATE next = {cur.Rr + dr[i], cur.Rc + dc[i], cur.Br + dr[i], cur.Bc + dc[i], cur.cnt + 1};
 
            if (next.cnt >= 11) continue;
            if (map[next.Rr][next.Rc] == '#' && map[next.Br][next.Bc] == '#') continue; // 둘 다 벽에 부딪히면 skip!
 
            // 벽에 부딪히면 그대로 유지처리!
            if (map[next.Rr][next.Rc] == '#') {
                next.Rr = cur.Rr; next.Rc = cur.Rc;
            }
            if (map[next.Br][next.Bc] == '#') {
                next.Br = cur.Br; next.Bc = cur.Bc;
            }
 
            // 바뀐 대로 진행!!
            if (next.Rr == next.Br && next.Rc == next.Bc) continue;
            if (map[next.Br][next.Bc] == 'H') continue;
            if (map[next.Rr][next.Rc] == 'H') return next.cnt;  // 정답!
             
            Q.push(next); //cout << "---push!---"<<endl;
        }
        // 팝!
        Q.pop();
    }
    return -1;     // 여기까지 도달하면 불가능한 것 -> -1 return.
}
int Solve()
{
    int sol = 0;
    sol = DoBFS();
    return sol;
}
 
void Init()
{
    memset(map, 0, sizeof(map));
    first.Rr = 0; first.Rc = 0;
    first.Br = 0; first.Bc = 0;
    first.cnt = 0;
    Q = {};     // 큐 초기화!!!
}
void InputData(){
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> map[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T, ans=-10;
    cin >> T;
    for (int i=0; i<T; i++){
        Init();     // map, state 메모리 초기화.
        InputData();//입력
 
        //여기서부터 작성
        ans = Solve();
 
        cout << ans << "\n";//출력
         
    }
    return 0;
}
/**************************************************************
    Problem: 5955
    Language: C++
    Result: Accepted
    Time:57 ms
    Memory:12728 kb
****************************************************************/