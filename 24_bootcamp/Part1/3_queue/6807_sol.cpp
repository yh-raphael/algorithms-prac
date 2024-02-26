#include <iostream>
#include <queue>
using namespace std;
 
#define MAXN (100)
int N;
int sol[MAXN + 10];
 
queue <int> que;
void Solve(void){
    int k = 0;
    // que = {};//큐 초기화
    for (int i=1; i<=N; i++){
        que.push(i);
    }
    for (int i=0; i<N-1; i++){
        int cnt = que.back() / 2;
        for (int j=0; j<cnt; j++){
            int r = que.front(); que.pop();
            que.push(r);
        }
        sol[k++] = que.front(); que.pop();
    }
    sol[k++] = que.front(); que.pop();
}
 
void InputData(){
    cin >> N;
}
 
void OutputData(){
    for (int i=0; i<N; i++){
        cout << sol[i] << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();//입력
    Solve();//여기서부터 작성
    OutputData();//출력
    return 0;
}
 
/**************************************************************
    Problem: 6807
    Language: C++
    Result: Accepted
    Time:1 ms
    Memory:2244 kb
****************************************************************/