#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];
 
int visited[MAX+10][MAX+10];    // FloodFill 할 때마다 써야해서 global!
int map[MAX+10][MAX+10];
int R, C;
vector<int> result;             // 정답 저장용.
 
void MakeMap()
{
    for (int i=0; i<K; i++) {
        int lr = sx[i];
        int lc = sy[i];
        int rr = ex[i];
        int rc = ey[i];
 
        for (int j=lr; j<rr; j++) { // row
            for (int k=lc; k<rc; k++) { // column
                map[j][k] = 1;      // 1 marking.
            }
        }
    }
}
void PrintMap()
{
    cout << "--- map ---" << endl;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}
void PrintVisited()
{
    cout << "--- visited ---" << endl;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
}
int FloodFill(int sr, int sc)
{
    int area = 0;
    struct state{
        int r,c;
        int rank;
    };
    queue<struct state> Q;
    int dr[] = {0,1,0,-1};
    int dc[] = {1,0,-1,0};
 
    Q.push({sr, sc, 1}); visited[sr][sc] = 1;
    while (!Q.empty()) {
        int cur_r = Q.front().r;
        int cur_c = Q.front().c;
        int cur_rank = Q.front().rank;
         
        area++;    // 방문한 node 개수가 누적 됨!
 
        for (int i=0; i<4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            int nrank = cur_rank + 1;
 
            if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
            if (visited[nr][nc]) continue;
            if (map[nr][nc]) continue;
 
            Q.push({nr, nc, nrank}); visited[nr][nc] = 1;
        }
        Q.pop();
    }
    return area;
}
void Solve()
{
    MakeMap();  //PrintMap();
 
    // 모든 점에 대해서 flood fill 수행.
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (map[i][j]) continue;        // 모눈종이 마킹 됨.
            if (visited[i][j]) continue;    // 이미 방문함.
            int cnt = FloodFill(i, j);
            result.push_back(cnt);
        }
    }
    // PrintVisited();
}
 
void InputData(){
    cin >> M >> N >> K;
    for (int i=0; i<K; i++){
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    }
    R = N; C = M;
}
void OutputAnswer()
{
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
}
int main(void){
    int ans = -1;
    InputData();//입력받는 부분
 
    //여기서부터 작성
    Solve();
 
    OutputAnswer();
    // OutputData(ans);//출력하는 부분
    return 0;
}
 
/**************************************************************
    Problem: 1150
    Language: C++
    Result: Accepted
    Time:15 ms
    Memory:2188 kb
****************************************************************/