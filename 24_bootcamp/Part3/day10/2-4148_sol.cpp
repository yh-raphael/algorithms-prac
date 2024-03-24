#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXH (12)
#define MAXW (6)
char map[MAXH+2][MAXW+2];
int visited[MAXH+2][MAXW+2];
struct POS{
    int h, w;
};
vector <POS> List;
int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};
void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}
void Init(){
    /*for (int i=1; i<=MAXH; i++){
        for (int j=1; j<=MAXW; j++){
            visited[i][j]=0;
        }
    }*/
    fill(visited[1], visited[MAXH+1], 0);
}
void CountFloodFill(int h, int w, char color){
    if (map[h][w] != color) return;
    if (visited[h][w] == 1) return;
    List.push_back({h, w});
    visited[h][w]=1;
    for (int i=0; i<4; i++){
        CountFloodFill(h+dh[i], w+dw[i], color);
    }
}
  
int ErasePuyo(){
    int flag=0;
    for (int h=1; h<=MAXH; h++){
        for (int w=1; w<=MAXW; w++){
            if (map[h][w] == '.') continue;
            if (visited[h][w] == 1) continue;
            List.clear();
            CountFloodFill(h, w, map[h][w]);//같은 뿌요 개수 파악
            if (List.size() < 4) continue;
            for (auto p : List){
                map[p.h][p.w] = '.';
            }
            flag=1;
        }
    }
    return flag;
}
void DownPuyo(){
    vector <char> puyo;
    for (int w=1; w<=MAXW; w++){
        puyo.clear();
        for (int h = 12; h > 0; h--){
            if (map[h][w] != '.') puyo.push_back(map[h][w]);
        }
        if (puyo.size() == 12) continue;
        int i = 0;
        for (int h = 12; h > 0; h--){
            if (i < puyo.size()) map[h][w] = puyo[i++];
            else map[h][w] = '.';
        }
    }
}
int Solve(){
    int combo=0;
    for (;;){
        //1.visited 배열 초기화
        Init();
        //2.같은색 뿌요가 4개 이상 모여있는 것들 모두 제거(제거한거 없으면 정지)
        if (ErasePuyo() == 0) break;
        combo++;
        //3.게임판 정리, 중력방향으로 떨어트리기
        DownPuyo();
    }
    return combo;
}
int main(){
    int T, t;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();
        int ans = Solve();
        cout << ans << endl;//출력하는 부분
    }
    return 0;
}