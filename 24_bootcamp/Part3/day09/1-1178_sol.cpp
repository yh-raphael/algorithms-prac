#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
    
#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
    
#define INF (50 * 50 * MAXN * MAXN)
int visited[MAXN][MAXN];//누적가중치
struct QUE {
    int h, w;
};
queue <QUE> que;
inline void push(int h, int w, int t) {
    if (visited[h][w] <= t) return;
    visited[h][w] = t;
    que.push({ h, w });
}
int BFS() {
    int dh[] = { -1, 1, 0, 0 };
    int dw[] = { 0, 0, -1, 1 };
    //1.초기화
    que = {};
    /*for (int h = 0; h <= N + 1; h++) {
        for (int w = 0; w <= N + 1; w++) {
            visited[h][w] = INF;
        }
    }*/
    fill(visited[0], visited[N+2], INF);
    //2.시작위치 큐에 저장
    push(0, 0, 0);
    /*for (int i = 0; i <= N + 1; i++) {
        push(0, i, 0);
        push(N + 1, i, 0);
        push(i, 0, 0);
        push(i, N + 1, 0);
    }*/
    //3.반복문
    while (!que.empty()) {
        QUE cur = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            int nh = cur.h + dh[i];
            int nw = cur.w + dw[i];
            if ((nh < 0) || (nh > N + 1) || (nw < 0) || (nw > N + 1)) continue;//범위 벗어남
            int power = map[cur.h][cur.w] - map[nh][nw];//현재 격자 높이  - 갈곳 격자 높이
            if (power < 0) power *= power;//음수면 오르막길이므로 제곱
            push(nh, nw, visited[cur.h][cur.w] + power);
        }
    }
    //4.결과
    return visited[eh][ew];
}
    
void InputData() {
    cin >> N;
    cin >> eh >> ew;
    for (int h = 1; h <= N; h++) {
        for (int w = 1; w <= N; w++) {
            cin >> map[h][w];
        }
    }
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력 받는 부분
    
    ans = BFS();//여기서부터 작성
    
    cout << ans << "\n";//출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1178
    Language: C++
    Result: Accepted
    Time:50 ms
    Memory:2328 kb
****************************************************************/