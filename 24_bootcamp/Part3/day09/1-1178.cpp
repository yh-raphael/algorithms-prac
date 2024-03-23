#include <iostream>
#include <queue>
using namespace std;
 
#define MAXN (102)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
 
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
 
typedef struct state{
    int r,c;
    int s;    //힘의 합.
} ST;
 
void InputData(){
    cin >> N;
    cin >> eh >> ew;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cin >> map[h][w];
        }
    }
}
int MakeDiff(int a, int b)
{
    if (a > b) return (a-b)*(a-b);
    else if (a == b) return 0;
    else if (a < b) return b-a;
}
int Solve()
{
    int sol = 1000000;
    for (int i=0; i<=N+1; i++) {
        for (int j=0; j<=N+1; j++) {
            visited[i][j] = 1000000;
        }
    }
     
    queue<ST> Q;
    Q.push({eh, ew, 0}); visited[eh][ew] = 0;
    while (!Q.empty()) {
        ST cur = Q.front(); Q.pop(); //cout << cur.r << " " << cur.c << " " << cur.s << endl;
        if (cur.r==0||cur.r==N+1||cur.c==0||cur.c==N+1) {
            // cout << "last: "<< cur.r << " " << cur.c << " " << cur.s << endl;
            if (sol > cur.s) sol = cur.s;
            // cout << "sol: " << sol << endl;
        }
        for (int i=0; i<4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr<0 || nr>N+1 || nc<0 || nc>N+1) continue;
             
            int diff = MakeDiff(map[cur.r][cur.c], map[nr][nc]);
            if (visited[nr][nc] <= cur.s + diff) continue;
            Q.push({nr, nc, cur.s + diff}); visited[nr][nc] = cur.s + diff;
        }
    }
    return sol;
}
int main(){
    int ans = -1;
    InputData();//입력 받는 부분
 
    //여기서부터 작성
    ans = Solve();
 
    cout << ans << endl;//출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1178
    Language: C++
    Result: Accepted
    Time:140 ms
    Memory:2832 kb
****************************************************************/