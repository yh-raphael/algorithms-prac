#include <iostream>
#include <queue>
using namespace std;
 
#define MAXN (100)
int W, H;//가로, 세로 크기
int sw, sh, ew, eh;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보
 
bool visited[MAXN+10][MAXN+10];
struct QUE{
    int h, w, t;
};
queue <QUE> que;
int BFS(){
    int dh[] = {-1, 1, 0, 0};
    int dw[] = {0, 0, -1, 1};
    //0.초기화
    fill(&visited[0][0], &visited[MAXN+10-1][MAXN+10], 0);
    que = {};
    //1.시작위치 큐에 저장
    que.push({sh, sw, 0});
    visited[sh][sw]=true;
    //2.반복문
    while (!que.empty()){
        QUE cur = que.front(); que.pop();
        if ((cur.h==eh) && (cur.w==ew)) return cur.t;//성공
        for (int i=0; i<4; i++){
            int nh = cur.h + dh[i];
            int nw = cur.w + dw[i];
            if (map[nh][nw] != '0') continue;
            if (visited[nh][nw]) continue;
            que.push({nh, nw, cur.t+1});
            visited[nh][nw]=true;
        }
    }
    //3.실패(이 문제는 이런 경우 없음)
    return -1;//디버깅을 위해...
}
 
void InputData(){
    cin >> W >> H;
    cin >> sw >> sh >> ew >> eh;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();//입력
 
    ans = BFS();//여기서부터 작성
 
    cout << ans << "\n";//출력
    return 0;
}
 
/**************************************************************
    Problem: 6827
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:2268 kb
****************************************************************/