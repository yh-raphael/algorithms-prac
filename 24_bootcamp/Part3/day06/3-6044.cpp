#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
#define MAX_N (300000)
 
queue<int> Q[20+10];
 
int N, K;
string name[MAX_N + 10];
 
void Input_Data(void) {
    string str;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> name[i];
    }
}
 
int CalComb(int n)
{
    return n*(n-1)/2;
}
long long Solve()
{
    long long cnt = 0;
    // 처음 K+1개 삽입!
    for (int i=0; i<K+1; i++) {
        Q[name[i].length()].push(i);   //index를 저장.
    }
    // 처음 K+1개! nC2 계산!
    for (int i=1; i<=20; i++) {
        if (!Q[i].size()) continue;
        cnt += CalComb(Q[i].size());
    }
    // 그 뒤부터 주욱~
    for (int i=K+1; i<N; i++) {
        Q[name[i-(K+1)].length()].pop();
        cnt += Q[name[i].length()].size();
        Q[name[i].length()].push(i);    // index를 저장.
    }
    return cnt;
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    long long sol = -1;
 
    // 입력 받는 부분
    Input_Data();
 
    // 여기서부터 작성
    sol = Solve();
 
    // 출력하는 부분
    cout << sol << '\n';
 
    return 0;
}