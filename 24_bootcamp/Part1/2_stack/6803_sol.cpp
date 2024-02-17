#include <iostream>
#include <stack>
using namespace std;
 
#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];
 
stack <int> stk;
 
int Solve(){
    int sol = 0, d;
    stk = {};//초기화
    stk.push(M[0]);
    for (int i=1; i<N; i++){
        switch (op[i]){
        case '+':
            stk.push(M[i]);
            break;
        case '-':
            stk.push(-M[i]);
            break;
        case '*':
            d = stk.top() * M[i];
            stk.pop();
            stk.push(d);
            break;
        case '/':
            d = stk.top() / M[i];
            stk.pop();
            stk.push(d);
        }
    }
    while (!stk.empty()){
        sol += stk.top();
        stk.pop();
    }
    return sol;
}
 
void InputData(){
    cin >> N;
    cin >> M[0];
    for(int i=1; i<N; i++){
        cin >> op[i] >> M[i];
    }
}
 
int main(){
    int ans = -1;
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    InputData();//입력
 
    ans = Solve();//여기서부터 작성
 
    cout << ans << "\n";
 
    return 0;
}
 
/**************************************************************
    Problem: 6803
    Language: C++
    Result: Accepted
    Time:1 ms
    Memory:2244 kb
****************************************************************/