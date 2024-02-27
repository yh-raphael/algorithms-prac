#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAXNM (100)
int N, M;//장기판 행의 수, 열의 수
int R, C, S, K;//말 행과 열, 졸 행과 열
 
bool visited[MAXNM+10][MAXNM+10];
struct QUE{
    int n, m, t;
};
queue <QUE> que;
 
int BFS(){
    int dn[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dm[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    //0.초기화
    memset(visited, 0, sizeof(visited));
    que = {};
    //1.시작위치 큐에 저장
    que.push({R, C, 0});
    visited[R][C]=true;
    //2.반복문
    while (!que.empty()){
        struct QUE cur = que.front(); que.pop();
        if ((cur.n==S) && (cur.m==K)) return cur.t;//성공
        for (int i=0; i<8; i++){
            int nn = cur.n+dn[i];
            int nm = cur.m+dm[i];
            if ((nn<1)||(nn>N)||(nm<1)||(nm>M)) continue;
            if (visited[nn][nm]) continue;
            que.push({nn, nm, cur.t+1});
            visited[nn][nm]=true;
        }
    }
    //3.실패(이 문제는 이런 경우 없음)
    return -1;//디버깅을 위해...
}
 
void InputData(){
    cin >> N >> M;
    cin >> R >> C >> S >> K;
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
    Problem: 6828
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:2256 kb
****************************************************************/