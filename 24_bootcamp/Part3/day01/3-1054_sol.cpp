#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N, P;
int used[MAXN+10];//[만들어진 값이 인덱스] = 만들어진 순서(1부터)
void InputData(void){
    cin >> N >> P;
}
int Solve(void){
    int i, next=N, sol = 0;
    used[N]=1;
    for (i=2; ; i++){
        next = next * N % P;
        if (used[next]){//순환 찾음
            sol = i - used[next];
            break;
        }
        used[next]=i;
    }
    return sol;
}
int main(void){
    int ans;
    InputData();
    ans = Solve();
    cout << ans << endl;
    return 0;
}
 
/**************************************************************
    Problem: 1054
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:2088 kb
****************************************************************/