#include <iostream>
#include <queue>
using namespace std;
 
#define MAXN (100)
int W, H;//지도의 가로 세로 크기
char char_map[MAXN+10][MAXN+10];
int map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int sw, sh;//시작위치 가로 세로 좌표
int num_z = 0;  // 저글링 수.
queue<pair <int,int>> Q;
 
int DoBFS(int sw, int sh)
{
    int dw[] = {1,0,-1,0};
    int dh[] = {0,1,0,-1};
    int duration = 0;
 
    num_z--;
    map[sh][sw] = 3;
    Q.push(make_pair(sw, sh)); // initial 사망시간을 맵에 저장.
    while (!Q.empty()) {
        int cw = Q.front().first;
        int ch = Q.front().second;
        duration = map[ch][cw];
        for (int i=0; i<4; i++) {
            int nw = cw + dw[i];
            int nh = ch + dh[i];
            if (nw < 1 || nw > W || nh < 1 || nh > H) continue;
 
            if (map[nh][nw] == 0) continue; // (i) 저글링 없음.
            else if (map[nh][nw] == 1) {    // (ii) 처음 방문.
                num_z--;                        // 저글링 죽이고.
                map[nh][nw] = duration + 1;     // 사망 시간도 관리.
                Q.push(make_pair(nw,nh));
            }
            else continue;                  // (iii) 이미 방문.
        }
        Q.pop();
    }
 
    return duration;
}
void CountZ()
{
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            if (map[i][j] == 1) {
                num_z++;
            }
        }
    }   
}
void ConvertToInt()
{
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            map[i][j] = char_map[i][j] - '0';
        }
    }   
}
void Solve()
{
    ConvertToInt();
    CountZ();
    int duration = DoBFS(sw, sh);
 
    cout << duration << endl;
    cout << num_z << endl;
}
 
void InputData(){
    cin >> W >> H;
    for (int i=1; i<=H; i++){
        cin >> &char_map[i][1];
    }
    cin >> sw >> sh;
}
int main(){
    InputData();//입력 받는 부분
 
    //여기서부터 작성
    Solve();
 
    return 0;
}