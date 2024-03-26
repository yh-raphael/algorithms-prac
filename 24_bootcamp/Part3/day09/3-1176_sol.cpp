#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN (128)
#define INF (MAXN * 1000)
struct LINK {
    char e;//도착지
    int d;//거리
};
vector <LINK> link[MAXN];
int visited[MAXN];//누적가중치
queue <char> que;
inline void push(char e, int d) {
    if (visited[e] <= d) return;
    visited[e] = d; que.push(e);
}
char BFS() {
    //1.초기화
    que = {};
    for (char i = 'A'; i <= 'z'; i++) visited[i] = INF;
    //2.시작위치 큐에 저장
    push('Z', 0); 
    //3.반복문(큐가 빌때까지 확산, 가중치가 다르므로)
    while (!que.empty()) {
        char cur = que.front(); que.pop();
        for (auto dest : link[cur]) {
            push(dest.e, visited[cur] + dest.d);
        }
    }
    //4.결과('A'~'Y' 최솟값을 갖는 인덱스를 찾기)
    char idx = 'A';//최솟값이 'A'라 가정
    for (char i = 'B'; i <= 'Y'; i++) {
        if (visited[idx] > visited[i]) idx = i;
    }
    return idx;
}
void InputData() {
    int P; char s, e; int d;
    cin >> P;
    for (int i = 'A'; i <= 'z'; i++) {
        link[i].clear();
    }
    for (int i = 0; i < P; i++) {
        cin >> s >> e >> d;
        link[s].push_back({ e, d });
        link[e].push_back({ s, d });
    }
}
int main() {
    InputData();
    char ans = BFS();
    cout << ans << " " << visited[ans];
    return 0;
}
/**************************************************************
    Problem: 1176
    Language: C++
    Result: Accepted
    Time:37 ms
    Memory:2356 kb
****************************************************************/