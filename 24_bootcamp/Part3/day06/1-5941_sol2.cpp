#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
#define MAXN ((int)1e4)
int M, T, N;//배에태울수있는수, 배이동시간, 손님수
int AT[MAXN + 10];
string SIDE[MAXN + 10];
 
int arrived[MAXN + 10];
 
queue<int>q[2]; // q[0]:왼쪽 선착장, q[1]:오른쪽 선착장
 
 
void InputData() {
    cin >> M >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> AT[i] >> SIDE[i];
 
        if (SIDE[i] == "left") q[0].push(i);
        else q[1].push(i);
    }
}
void OutputData() {
    for (int i = 0; i < N; i++) {
        cout << arrived[i] << "\n";
    }
}
 
void Solve() {
    // 1. Simulation
    int side = 0; // 0: 왼쪽 1: 오른쪽
    int time = 0; // 시간
    int arv_cnt = 0; // 옮긴 사람의 수
 
 
 
 
    while (arv_cnt < N) { // 모두를 이동해야함
 
        // 현재 선착장에 있어도 되는 경우 (선착장이 비어있지 않고, 처음 사람이 배에 탈 수 있음)
        if (!q[side].empty() && (time >= AT[q[side].front()])) {
            int cnt = 0; // 옮길 수 있는 사람의 수
            // 선착장에서 사람이 타는 경우(선착장이 비어있지 않고, 배에 자리 있음)
            while (!q[side].empty() && (cnt < M)) {
                // 현재 선착장에 있는 사람
                int i = q[side].front();
                // 만약에 아직 도착 안한 사람이었으면 break;
                if (AT[i] > time) break;
                // 선착장에서 사람 빼기
                q[side].pop();
                arrived[i] = time + T;
                cnt++;
                arv_cnt++;
            }
            // 다태웠으면 반대 방향으로 배 이동
            time += T;
            side = 1 - side; // side^=1; // bit shift
        }
        // 선착장을 이동해야하는 경우,
        else {
            // 현재 선착장에 아무도 없을때,
            if (q[side].empty()) {
                side = 1 - side;
                // 반대 선착장에 사람이 없으면 사람이 있을때까지 기다렸다가 이동해야함
                if (time < AT[q[side].front()]) {
                    time = AT[q[side].front()];
                }
                // 이동
                time += T;
            }
            // 현재 선착장을 기다리면 사람이 올수도 있음
            else {
                // 다음 선착장에 사람이 먼저 오는 경우
                int i = q[side].front();
                if (!q[1 - side].empty() && AT[q[side].front()] > AT[q[1 - side].front()]) {
                    side = 1 - side;
                    i = q[side].front();
                    if (time < AT[i]) time = AT[i];
                    time += T;
                }
                // 현재 선착장에 사람이 먼저 오는 경우
                else {
                    time = AT[i];
                }
            }
 
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    InputData();//입력받는 부분
 
    //여기서부터 작성
    Solve();
 
    OutputData();//출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 5941
    Language: C++
    Result: Accepted
    Time:30 ms
    Memory:2640 kb
****************************************************************/