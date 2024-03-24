#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAXH (12)
#define MAXW (6)
 
char map[MAXH+2][MAXW+2];
int visited[MAXH+2][MAXW+2];
struct cord{
    int r,c;
};
 
void PrintMap()
{
    cout << "--- map ---" << endl;
    for (int i=1; i<=MAXH; i++) {
        for (int j=1; j<=MAXW; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
void RemoveElement(vector<struct cord> V)
{
    for (int i=0; i<V.size(); i++) {
        int r = V[i].r;
        int c = V[i].c;
        map[r][c] = '.';
    }
}
int FloodFill(int sr, int sc, char color)   // 터트린 element 개수 return.
{
    int cnt = -1;
    queue<struct cord> Q;
    vector<struct cord> V;  // 후보군 저장.
    int dr[] = {0,1,0,-1};
    int dc[] = {1,0,-1,0};
 
    // cout << "-------------" << endl;
    Q.push({sr, sc}); visited[sr][sc] = 1; V.push_back({sr, sc});
    while (!Q.empty()) {
        int cur_r = Q.front().r;
        int cur_c = Q.front().c;
 
        // cout << "cur_r: " << cur_r << ", cur_c: " << cur_c << endl;
        for (int i=0; i<4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
 
            if (nr<1 || nr>MAXH || nc<1 || nc>MAXW) continue;
            if (visited[nr][nc]) continue;
            if (map[nr][nc] == '.') continue;
 
            if (map[nr][nc] == color) {
                Q.push({nr, nc}); visited[nr][nc] = 1; V.push_back({nr, nc});
            }
        }
        Q.pop();
    }
 
    // 4개 이상이면 터트리자.
    if (V.size() >= 4) {
        RemoveElement(V);
        cnt = V.size();
    }
    else {
        cnt = 0;
    }
    return cnt;
}
bool PulloPop()
{
    memset(visited, 0, sizeof(visited));
    bool IsEnd = true;
    for (int i=1; i<=MAXH; i++) {
        for (int j=1; j<=MAXW; j++) {
            if (map[i][j] == '.') continue;
            if (visited[i][j] == 1) continue;
            int cnt = FloodFill(i, j, map[i][j]);    // 하고 나면 하나의 터트림 가능한 group에 대해서 map이 바뀌어있음.
            if (cnt > 0) IsEnd = false;
        }
    }
    return IsEnd;   // 더 못 터트리는 경우.
}
void ApplyGravity()
{
    // 모든 column에 대해 수행.
    for (int j=1; j<=MAXW; j++) {
        int low_i = 12;
        for (int i=MAXH; i>0; i--) {
            if (map[i][j] == '.') continue;
            if (low_i != i) {   // 내려가야 할 칸의 위치가 저장돼있음!
                map[low_i][j] = map[i][j];
                map[i][j] = '.';
            }
            low_i--;
        }
    }
}
int Solve()
{
    int cycle = 0;
    while (1) {
        if (PulloPop()) break;
        // PrintMap();  
        ApplyGravity();         // 하고 나면 element들이 아래로 정렬됨.
        // PrintMap();
        cycle++;
    }
    return cycle;
}
 
void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}
int main(){
    int T, t, ans = -1;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분
 
        //여기서부터 작성
        ans = Solve();
 
        cout << ans << endl;//출력하는 부분
    }
    return 0;
}