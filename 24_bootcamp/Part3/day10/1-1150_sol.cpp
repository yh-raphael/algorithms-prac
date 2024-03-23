#include <iostream>
#include <algorithm>
using namespace std;
 
#define MAXN (100)
int H, W;//세로, 가로크기
int map[MAXN+10][MAXN+10];//0:빈영역, 1:직사각형 내부, 2:방문표시
int sol[MAXN * MAXN];
int area;
int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};
void FillMap(int sh, int sw, int eh, int ew){
    for (int h=sh; h<eh; h++){
        for (int w=sw; w<ew; w++){
            map[h][w]=1;
        }
    }
}
void InputData(){
    int K, sw, sh, ew, eh;
    cin >> H >> W >> K;
    for (int i=0; i<K; i++){
        cin >> sw >> sh >> ew >> eh;
        FillMap(sh, sw, eh, ew);
    }
}
void FloodFill(int h, int w){
    //1.종료조건 및 표시
    if ((h<0)||(h>=H)||(w<0)||(w>=W)) return;//범위 벗어남
    if (map[h][w] != 0) return;
    map[h][w]=2;
    area++;
    //2.확산
    for (int i=0; i<4; i++){
        FloodFill(h+dh[i], w+dw[i]);
    }
}
int Solve(){
    int cnt = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (map[i][j] != 0) continue;
            area = 0;
            FloodFill(i, j);//상하좌우 연결된 빈영역 방문
            sol[cnt++] = area;
        }
    }
    return cnt;
}
void OutputData(int ans){
    cout << ans << endl;
    sort(sol, sol+ans);//오름차순 정렬
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}
int main(){
    InputData();
    int ans = Solve();
    OutputData(ans);
    return 0;
}
 
/**************************************************************
    Problem: 1150
    Language: C++
    Result: Accepted
    Time:3 ms
    Memory:2176 kb
****************************************************************/