#include <iostream>
#include <queue>
#include <cstring>
 
using namespace std;
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
 
typedef struct state{
    int Rr, Rc;
    int Br, Bc;
    int cnt;
} ST;
ST first;
bool visited[MAXN+5][MAXN+5][MAXN+5][MAXN+5];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
 
void InputData(){
    cin >> R >> C;
    for (int i=1; i<=R; i++){
        cin >> &map[i][1];
    }
}
void Init()
{
    memset(visited, 0, sizeof(visited));
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            if (map[i][j] == 'R') {
                first.Rr = i;
                first.Rc = j;
            }
            if (map[i][j] == 'B') {
                first.Br = i;
                first.Bc = j;
            }
        }
    }
    first.cnt = 0;
}
int DoBFS()
{
    queue<ST> Q;
    Q.push(first); visited[first.Rr][first.Rc][first.Br][first.Bc] = true;
     
    while (!Q.empty()) {
        ST cur = Q.front(); Q.pop();
        // cout << cur.Rr << " " << cur.Rc << " " << cur.Br << " " << cur.Bc << " " << cur.cnt << endl;
        if (cur.cnt >= 10) break;
         
        for (int i=0; i<4; i++) {
            int nRr = cur.Rr + dr[i];
            int nRc = cur.Rc + dc[i];
            int nBr = cur.Br + dr[i];
            int nBc = cur.Bc + dc[i];
             
            if (map[nRr][nRc] == '#') {
                nRr = cur.Rr;
                nRc = cur.Rc;
            }
            if (map[nBr][nBc] == '#') {
                nBr = cur.Br;
                nBc = cur.Bc;
            }
            if (visited[nRr][nRc][nBr][nBc]) continue;
             
            if (map[nBr][nBc] == 'H') continue;
            if (nRr == nBr && nRc == nBc) continue;
             
            if (map[nRr][nRc] == 'H') return cur.cnt + 1;
            ST next = {nRr, nRc, nBr, nBc, cur.cnt + 1};
            Q.push(next); visited[nRr][nRc][nBr][nBc] = true;
        }
    }
    return -1;
}
int Solve()
{
    Init();
    return DoBFS();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int T, ans=-10;
    cin >> T;
    for (int i=0; i<T; i++){
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
    Time:15 ms
    Memory:2400 kb
****************************************************************/