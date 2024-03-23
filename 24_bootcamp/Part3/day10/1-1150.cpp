#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];
 
int map[MAX+10][MAX+10];
int sol[MAX * MAX];//각 영역 넓이 저장용
typedef struct state{
    int r,c;
} ST;
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
 
void FillMap(int a, int b, int c, int d)
{
    for (int i=a; i<c; i++) {
        for (int j=b; j<d; j++) {
            map[i][j] = 1;
        }
    }
}
void InputData(){
    cin >> M >> N >> K;
    for (int i=0; i<K; i++){
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
        FillMap(sx[i], sy[i], ex[i], ey[i]);
    }
}
void OutputData(int ans){
    cout << ans << endl;
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}
// int FloodFill(int r, int c)      // BFS.
// {
//     int cnt = 0;
//     queue<ST> Q;
//     Q.push({r, c}); map[r][c] = 2;
//     while (!Q.empty()) {
//         ST cur = Q.front(); Q.pop(); //cout << cur.r<<" " <<cur.c<<endl;
//         cnt++;
//         for (int i=0; i<4; i++) {
//             int nr = cur.r + dr[i];
//             int nc = cur.c + dc[i];
//             if (nr<0||nr>=N||nc<0||nc>=M) continue;
//             if (map[nr][nc] == 0) {
//                 Q.push({nr, nc}); map[nr][nc] = 2;
//             }
//         }
//     }
//     return cnt;
// }
int area = 0;
void FloodFill(int r, int c)        // DFS.
{
    //1.가지치기
    if (r<0 || r>=N || c<0 || c>=M) return;
    //2.종료조건
    if (map[r][c] != 0) return;
    //3.처리
    map[r][c] = 2; area ++;
    //4.확산
    for (int i=0; i<4; i++) {
        FloodFill(r + dr[i], c + dc[i]);
    }
}
int Solve()
{
    int k=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j] == 0) {
                area = 0;
                FloodFill(i, j);
                sol[k++] = area;
                // sol[k++] = FloodFill(i, j);
            }
        }
    }
    sort(sol, sol+k);
    return k;
}
int main(void){
    int ans = -1;
    InputData();//입력받는 부분
 
    //여기서부터 작성
    ans = Solve();
 
    OutputData(ans);//출력하는 부분
    return 0;
}
 
/**************************************************************
    Problem: 1150
    Language: C++
    Result: Accepted
    Time:17 ms
    Memory:2176 kb
****************************************************************/