#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXH (12)
#define MAXW (6)
  
char map[MAXH+2][MAXW+2];
bool visited[MAXH+2][MAXW+2];
  
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
typedef struct cord{
    int r, c;
} CORD;
int cnt;
  
void PrintMap()
{
    cout << "cnt: " << cnt << endl;
    for (int i=1; i<=MAXH; i++) {
        for (int j=1; j<=MAXW; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}
//1. FloodFill & Remove.
int area = 0;
vector<CORD> V;
void FloodFill(int r, int c, char color)
{
    if (r<1 || r>MAXH || c<1 || c>MAXW) return;
    if (visited[r][c]) return;
    if (map[r][c] != color) return;
      
    area++; visited[r][c] = true; V.push_back({r, c});
    for (int i=0; i<4; i++) {
        FloodFill(r + dr[i], c + dc[i], color);
    }
}
void Remove()
{
    for (int i=0; i<V.size(); i++) {
        map[V[i].r][V[i].c] = '.';
    }
}
bool PopStones()
{
    bool flag = false;
    for (int i=1; i<=MAXH; i++) {
        for (int j=1; j<=MAXW; j++) {
            if (map[i][j] == '.') continue;
            if (visited[i][j]) continue;
              
            area = 0; V.clear();
            FloodFill(i, j, map[i][j]);
              
            if (area >= 4) {
                Remove(); flag = true;
            }
        }
    }
    if (flag) cnt++;
    // PrintMap();
    return flag;
}
//2. DropStones.
void DropStones()
{
    vector<char> tmp;
    for (int c=1; c<=MAXW; c++) {
        //1.한 열 조사.
        for (int r=MAXH; r>=1; r--) {
            if (map[r][c] != '.') {
                tmp.push_back(map[r][c]);
            }
        }
        //2.밑에서부터 marking.
        for (int i=0; i<tmp.size(); i++) {
            map[MAXH - i][c] = tmp[i];
        }
        //3.공백 marking.
        for (int i=tmp.size(); i<MAXH; i++) {
            map[MAXH - i][c] = '.';
        }
        tmp.clear();
    }
    // PrintMap();
}
int Solve()
{
    while (PopStones()) {
        DropStones();
        memset(visited, 0, sizeof(visited));
    }
    return cnt;
}
int main(){
    int T, t, ans = -1;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분
  
        //여기서부터 작성
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        ans = Solve();
  
        cout << ans << endl;//출력하는 부분
    }
    return 0;
}