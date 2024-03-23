#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN (50)
 
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];
bool visited[MAXN+10][MAXN+10];
typedef struct state{
    int r,c;
    int t;
    int mode;   //0:홍수, 1:화가
} ST;
queue<ST> Q;
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
    Q = {};
    int sr=0, sc=0;
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            if (map[i][j] == '*') {
                Q.push({i, j, 0, 0});
            }
            if (map[i][j] == 'S') {
                sr=i; sc=j;
            }
        }
    }
    Q.push({sr, sc, 0, 1}); visited[sr][sc] = true;
}
int DoBFS()
{
    while (!Q.empty()) {
        ST cur = Q.front(); Q.pop();
        // cout << "cur-> r: " << cur.r<< ", c: " << cur.c<<endl;
        for (int i=0; i<4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
             
            if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
            if (map[nr][nc] == '*') continue;
            if (map[nr][nc] == 'X') continue;
             
            if (cur.mode == 0) {
                if (map[nr][nc] == 'D') continue;
                Q.push({nr, nc, cur.t+1, cur.mode}); map[nr][nc] = '*';
            }
            else if (cur.mode == 1) {
                if (visited[nr][nc]) continue;
                if (map[nr][nc] == 'D') return cur.t+1;
                if (map[nr][nc] == '.') {
                    Q.push({nr, nc, cur.t+1, cur.mode}); visited[nr][nc] = true;
                    // map[nr][nc] = 'S';
                    // cout << nr << " " << nc << " " << cur.t+1 << endl;
                }
            }
        }
    }
    return -2;
}
int Solve()
{
    Init();
    return DoBFS();
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
     
    int T, ans = -1;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력 받는 부분
        // 여기서부터 작성
        ans = Solve();
        if (ans == -2) cout << "KAKTUS" << endl;//출력 하는 부분
        else cout << ans << endl;
    }
    return 0;
}
/**************************************************************
    Problem: 2926
    Language: C++
    Result: Accepted
    Time:15 ms
    Memory:2096 kb
****************************************************************/