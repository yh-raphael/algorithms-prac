#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
 
#define MAXN 10000
int S, E;           //출발 정류장 번호, 도착 정류장 번호
int prime[MAXN+10];    //소수 여부 표시(1:소수아님, 0:소수)
bool visited[MAXN+10];
typedef struct state{
    int n, t;
} ST;
 
void InputData(){
    cin >> S >> E;
}
void ResolvePrime()   // 에라토스테네스의 체.
{
    prime[0] = 1;
    prime[1] = 1;
    for (int i=2; i<MAXN; i++) {
        if (prime[i] == 1) continue;
        for (int k=i+i; k<MAXN; k+=i) {
            prime[k] = 1;
        }
    }
    for (int i=2; i<1000; i++) {    // 4자리수만 prime으로 처리.
        prime[i] = 1;
    }
}
int DoBFS()
{
    queue<ST> Q;
    Q.push({S, 0}); visited[S] = true;
     
    while (!Q.empty()) {
        ST cur = Q.front(); Q.pop(); //cout << cur.n << " " << cur.t << endl;
        if (cur.n == E) return cur.t;
         
        int div = 1;
        for (int i=0; i<4; i++) {
            int next = cur.n;
            int digit = (cur.n / div) % 10;
             
            for (int j=1; j<=9; j++) {
                next -= digit * div;
                digit = (digit+1) % 10;
                next += digit * div;                
                 
                if (visited[next]) continue;
                if (prime[next] == 0) {
                    Q.push({next, cur.t + 1}); visited[next] = true;
                }
            }
             
            div *= 10;
        }
    }
}
int Solve()
{
    //1. 소수인지 아닌지 구하기.
    ResolvePrime();
    //2. BFS.
    return DoBFS();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int ans = -1;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = Solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1160
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:2292 kb
****************************************************************/