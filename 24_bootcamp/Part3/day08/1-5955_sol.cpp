#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
 
int srh, srw, sbh, sbw;
bool visited[MAXN+5][MAXN+5][MAXN+5][MAXN+5];//[빨간구슬세로][빨간구슬가로][파란구슬세로][파란구슬가로]
struct QUE{
    int rh, rw, bh, bw, t;//빨간구슬세로가로, 파란구슬세로가로, 가중치(횟수)
};
queue <QUE> que;
inline void push(int rh, int rw, int bh, int bw, int t){
    if (visited[rh][rw][bh][bw]) return;
    visited[rh][rw][bh][bw] = true;
    que.push({rh, rw, bh, bw, t});
}
void SearchStartPos(){
    int flag = 0;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            if (map[i][j] == 'R'){
                srh=i; srw=j;
                if (flag == 1) return;//'R', 'B' 모두 찾았으면 종료
                flag = 1;
            }
            else if (map[i][j] == 'B'){
                sbh=i; sbw=j;
                if (flag == 1) return;//'R', 'B' 모두 찾았으면 종료
                flag = 1;
            }
        }
    }
}
int BFS(){
    int dh[] = {1, -1, 0, 0};//상하좌우
    int dw[] = {0, 0, -1, 1};
    //1.초기화
    que = {};
    memset(visited, 0, sizeof(visited));
    //2.시작위치 큐에 저장
    SearchStartPos();
    push(srh, srw, sbh, sbw, 0);
    //3.반복문
    while(!que.empty()){
        QUE cur = que.front(); que.pop();
        if (cur.t >= 10) break;//10회 진행했으므로 실패
        for (int i=0; i<4; i++){//상하좌우 4방향 시도
            int nrh = cur.rh + dh[i];
            int nrw = cur.rw + dw[i];
            int nbh = cur.bh + dh[i];
            int nbw = cur.bw + dw[i];
            if (map[nrh][nrw] == '#'){//이동할 곳이 벽
                nrh = cur.rh; nrw = cur.rw;//원래자리
            }
            if (map[nbh][nbw] == '#'){
                nbh = cur.bh; nbw = cur.bw;
            }
            if ((nrh == nbh) && (nrw == nbw)) continue;//동일 자리면 구슬 깨짐, 이런경우는 skip
            if (map[nbh][nbw] == 'H') continue;//파란 구슬이 목표구멍에 들어가면 실패, skip
            if (map[nrh][nrw] == 'H') return cur.t+1;//성공
            push(nrh, nrw, nbh, nbw, cur.t+1);
        }
    }
    //4.실패
    return -1;
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
        InputData();//입력
 
        ans = BFS();//여기서부터 작성
 
        cout << ans << "\n";//출력
    }
    return 0;
}
 
/**************************************************************
    Problem: 5955
    Language: C++
    Result: Accepted
    Time:2 ms
    Memory:2400 kb
****************************************************************/