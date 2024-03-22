#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
using namespace std;
 
#define MAX_N (300000)
 
int N, K;
string name[MAX_N + 10];
 
int cnt[20 + 1];
queue <int> que;
long long Solve() {
    long long ans = 0;
    que = {};
    for (int i = 0; i <= K; i++) {
        ans += cnt[name[i].size()]++;
        que.push(name[i].size());
    }
    for (int i = K + 1; i < N; i++) {
        cnt[que.front()]--;
        que.pop();
 
        ans += cnt[name[i].size()]++;
        que.push(name[i].size());
    }
    return ans;
}
 
void Input_Data(void) {
    string str;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> name[i];
    }
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    long long sol = -1;
 
    // 입력 받는 부분
    Input_Data();
 
    sol = Solve();// 여기서부터 작성
 
    // 출력하는 부분
    cout << sol << '\n';
 
    return 0;
}
/**************************************************************
    Problem: 6044
    Language: C++
    Result: Accepted
    Time:51 ms
    Memory:26276 kb
****************************************************************/