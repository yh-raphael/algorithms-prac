#include <iostream>
#include <queue>
using namespace std;
    
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN + 10][MAXN + 10];
    
#define INF ((int)2e9)
struct QUE {
    int r, c, t, mode;//0:홍수, 1:화가
};
queue <QUE> que;
    
int BFS() {
    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };
    //0.초기화
    que = {};
    //1.시작위치 큐에 저장(홍수를 저장하고, 마지막으로 화가저장)
    int sr = 0, sc = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] == '*') {//홍수
                que.push({ r, c, 0, 0 });
            }
            else if (map[r][c] == 'S') {//화가
                sr = r; sc = c;
            }
        }
    }
    que.push({ sr, sc, 0, 1 });//화가는 마지막에 저장
    //2.반복문(도착할때까지)
    while (!que.empty()) {
        QUE cur = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if ((nr < 0) || (nr >= R) || (nc < 0) || (nc >= C)) continue;
            if ((map[nr][nc] == '*') || (map[nr][nc] == 'X')) continue;
            if (cur.mode == 0) {//홍수
                if (map[nr][nc] == 'D') continue;
                que.push({ nr, nc, 0, 0 });
                map[nr][nc] = '*';
            }
            else {//화가
                if (map[nr][nc] == 'D') return cur.t + 1;//성공
                if (map[nr][nc] != '.') continue;
                que.push({ nr, nc, cur.t + 1, 1 });
                map[nr][nc] = 'S';
            }
        }
    }
    //3.실패
    return -1;
}
    
void InputData() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> map[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    
    int T, ans = -1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        InputData();//입력 받는 부분
        ans = BFS();// 여기서부터 작성 
        if (ans == -1) cout << "KAKTUS" << "\n";//출력 하는 부분
        else cout << ans << "\n";
    }
    return 0;
}
/**************************************************************
    Problem: 2926
    Language: C++
    Result: Accepted
    Time:15 ms
    Memory:2248 kb
****************************************************************/