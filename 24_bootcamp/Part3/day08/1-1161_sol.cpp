#include <iostream>
#include <queue>
using namespace std;
 
#define MAXN (100)
int W, H;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int sw, sh;//시작위치 가로 세로 좌표
 
struct QUE{
    int h, w, t;//세로, 가로, 시간
};
queue <QUE> que;
void push(int h, int w, int t){
    if (map[h][w] != '1') return;//저글링 아님(범위 벗어났음 or 빈곳 or 이미 방문한 곳)
    map[h][w]='0';//방문표시
    que.push({h, w, t});
}
int BFS(){
    int dh[] = {-1, 1, 0, 0};
    int dw[] = {0, 0, -1, 1};
    QUE cur = {0, 0, 0};
    //1.초기화
    que = {};
    //2.시작위치 큐에 저장
    push(sh, sw, 3);
    //3.반복문
    while(!que.empty()){
        cur = que.front(); que.pop();
        for (int i=0; i<4; i++){
            push(cur.h+dh[i], cur.w+dw[i], cur.t+1);
        }
    }
    //4.결과리턴
    return cur.t;//마지막에 죽은 저글링 시간
}
void InputData(){
    cin >> W >> H;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
    cin >> sw >> sh;
}
void OutputData(int t){
    int cnt=0;
    cout << t << '\n';
    for (int i=1; i<=H; i++){
        for (int j=1; j<=W; j++){
            if (map[i][j] == '1') cnt++;
        }
    }
    cout << cnt << '\n';
}
int main(){
    InputData();
    int ans = BFS();
    OutputData(ans);
    return 0;
}
 