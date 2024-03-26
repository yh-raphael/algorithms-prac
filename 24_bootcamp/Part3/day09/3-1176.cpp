#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN (128)
#define INF (MAXN * 1000)
typedef struct node{
    char e;
    int d;
} NODE;

vector<NODE> G[MAXN];
int visited[MAXN];
queue<char> Q;

int P;
char farm;

inline void push(char e, int d) {
    if (visited[e] <= d) return;
    visited[e] = d; Q.push(e);
}
char Solve()
{
    //1.초기화.
    for (char i='A'; i<='z'; i++) visited[i] = INF;
    //2.시작위치 큐에 저장.
    push('Z', 0);
    //3.반복문(큐가 빌 때까지 확산, 가중치가 다르므로)
    while (!Q.empty()) {
        char cur = Q.front(); Q.pop();
        for (int i=0; i<G[cur].size(); i++) {
            push(G[cur][i].e, visited[cur] + G[cur][i].d);
        }
    }
    //4.결과.
    char idx = 'A';
    for (char i='B'; i<='Y'; i++) {
        if (visited[idx] > visited[i]) idx = i;
    }
    return idx;
}

void InputData() {
    char s, e;
    int d;
    cin >> P;
    // 바로 graph 빌드.
    for (int i=0; i<P; i++) {
        cin >> s >> e >> d;
        G[s].push_back({e, d});
        G[e].push_back({s, d});
    }
}
int main(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    farm = Solve();

    cout << farm << " " << visited[farm] << endl;// 출력하는 부분
    return 0;
}
