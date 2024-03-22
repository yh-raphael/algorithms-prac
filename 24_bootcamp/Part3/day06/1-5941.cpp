#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
#define MAXN ((int)1e4)
int M, T, N;//배에태울수있는수, 배이동시간, 손님수
int AT[MAXN + 10];
string SIDE[MAXN + 10];
int arrived[MAXN + 10];
 
queue<int> Q[2];    // 0:left, 1:right.
 
void InputData() {
    cin >> M >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> AT[i] >> SIDE[i];
        // 양쪽 Queue에 넣기.
        if (SIDE[i] == "left") Q[0].push(i);
        else Q[1].push(i);
    }
}
void OutputData() {
    for (int i = 0; i < N; i++) {
        cout << arrived[i] << "\n";
    }
}
void Solve()
{
    int cur_s = 0;  // side, 0:left, 1:right.
    int cur_t = 0;  // time.
    while (!Q[0].empty() || !Q[1].empty()) {
        int cnt = 0;    // 배 탑승 인원.
        // cout << "cur_t: " << cur_t << endl;
        // cout << "cur_s: " << cur_s << endl;
        // (1) 현재 시간까지 도착한 인원을, (2) 배의 capacity까지, 태우자.
        while (!Q[cur_s].empty() && AT[Q[cur_s].front()] <= cur_t && cnt < M) {
            cnt++;
            arrived[Q[cur_s].front()] = cur_t + T;   // 인원을 반대로 옮긴다! (도착시간 <- 현재시간 + T)
            Q[cur_s].pop();     // 큐에서 제거.
        }
        // cout << "--cnt: "<< cnt<<endl;
        // (1-1) 배에 인원 있음 
        if (cnt > 0) {
            // 배이동시간 누적.
            cur_t += T;
            // 현재side flip!
            cur_s = (cur_s + 1) % 2;
        }
        // (1-2) 배에 없음 -> cur_time 증가.
        else {
            // 반대쪽에 기다리는 사람 있는 경우 -> 배만 이동.
            if (!Q[(cur_s+1)%2].empty() && AT[Q[(cur_s+1)%2].front()] <= cur_t ) {
                cur_t += T;
                cur_s = (cur_s + 1) % 2;
            }
            // 없는경우 -> 시간 1초 증가.
            else {
                cur_t += 1;
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