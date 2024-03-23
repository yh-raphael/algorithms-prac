#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int C, R;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int sc, sr;//시작위치 가로 세로 좌표

bool visited[MAXN+10][MAXN+10];
typedef struct state{
    int r,c;
    int t;
} ST;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void InputData(){
    cin >> C >> R;
    for (int i=1; i<=R; i++){
        cin >> &map[i][1];
    }
    cin >> sc >> sr;
}
int DoBFS()
{
    int last_t = -2;
    queue<ST> Q;
    //1. 시작점 넣기.
    ST first = {sr, sc, 3};
    Q.push(first); visited[sr][sc] = true;
    // 하나씩 꺼내면서 시작.
    int cnt = 0;
    while (!Q.empty()) {
        ST cur = Q.front(); Q.pop(); last_t = cur.t;
        // 4방에 대해서.
        for (int i=0; i<4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (visited[nr][nc]) continue;
            if (map[nr][nc] == '1') {
                ST next = {nr, nc, cur.t + 1};
                Q.push(next); visited[nr][nc] = true;
            }
        }
    }
    return last_t;
}
int CountRemaining()
{
    int start = 0;
    int end = 0;
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            if (map[i][j] == '1') start++;
        }
    }
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            if (visited[i][j] == true) end++;
        }
    }
    return start - end;
}
void Solve()
{
    cout << DoBFS() << '\n';
    cout << CountRemaining() << '\n';
}
int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    Solve();

    return 0;
}