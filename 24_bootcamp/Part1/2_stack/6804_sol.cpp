#include <iostream>
#include <stack>
using namespace std;
 
#define MAXN ((int)1e5)
int N;//빌딩수
int H[MAXN+10];//빌딩높이
int sol[MAXN+10];//각 빌딩에서 보이는 빌딩 번호
 
stack <int> stk;
 
void Solve(){
    stk = {};
    for (int i=1; i<=N; i++){
        //1.스택에 i번 빌딩보다 낮은 빌딩은 i번 빌딩을 봄(저장, 제거)
        while(!stk.empty() && (H[stk.top()] < H[i])){
            sol[stk.top()] = i;
            stk.pop();
        }
        //2.i번 빌딩은 스택에 저장
        stk.push(i);
    }
}
 
void InputData() {
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> H[i];
    }
}
void OutputData() {
    for (int i=1; i<=N; i++){
        cout << sol[i] << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    InputData();//입력받는 부분
 
    Solve();//여기서부터 작성
 
    OutputData();//출력하는 부분
    return 0;
}
 
/**************************************************************
    Problem: 6804
    Language: C++
    Result: Accepted
    Time:18 ms
    Memory:3428 kb
****************************************************************/