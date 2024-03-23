#include <iostream>
#include <queue>
using namespace std;
#define MAXN ((int)1e4)
int S, E;//출발 정류장 번호, 도착 정류장 번호
int prime[MAXN];//소수 여부 표시(1:소수아님, 0:소수)
int visited[MAXN];//방문표시
    
struct QUE {
    int n, t;//정류장 번호, 시간
};
queue <QUE> que;
void push(int n, int t) {
    if (visited[n] == 1) return;//이미 방문
    if (prime[n] == 1) return;//소수아님, 정류장 아님
    visited[n] = 1; que.push({ n, t });
}
void D2C(int org, int *arr) {
    arr[0] = org / 1000; org %= 1000;
    arr[1] = org / 100; org %= 100;
    arr[2] = org / 10;
    arr[3] = org % 10;
}
int C2D(int *arr) {
    return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}
int BFS() {
    int num[4];
    //1.초기화
    que = {};
    //2.시작위치 큐에 저장
    push(S, 0);
    //3.반복문
    while (!que.empty()) {
        QUE cur = que.front(); que.pop();
        if (cur.n == E) return cur.t;//도착 성공
        D2C(cur.n, num);//각 자리수를 배열 저장
        for (int idx = 0; idx < 4; idx++) {
            int backup = num[idx];//백업
            for (int k = idx == 0; k <= 9; k++) {
                num[idx] = k;//한자리만 다른 값 으로 변경
                int dest = C2D(num);
                push(dest, cur.t + 1);
            }
            num[idx] = backup;//복원
        }
    }
    //4.실패(이 문제는 이런경우 없음)
    return -1;//디버깅을 위해...
}
void MakePrime() {//에라스토테네스체
    prime[0] = prime[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (prime[i] == 1) continue;
        for (int k = i + i; k < MAXN; k += i) {
            prime[k] = 1;
        }
    }
}
void InputData() {
    cin >> S >> E;
}
int main() {
    MakePrime();
    InputData();
    int ans = BFS();
    cout << ans << endl;// 출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1160
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:2168 kb
****************************************************************/