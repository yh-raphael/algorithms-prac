#include <iostream>
#include <stack>
using namespace std;
#define MAXN ((int)5e5)
int N, K;
char str[MAXN + 10];
 
stack <char> stk;
 
void Solve() {
    stk = {};
    for (int i = 0; i < N; i++) {
        while (!stk.empty() && K && (stk.top() < str[i])) {
            stk.pop();
            K--;
        }
        stk.push(str[i]);
    }
    while (K-- > 0) {
        stk.pop();
    }
    int len = stk.size();
    str[len] = 0;
    while (!stk.empty()) {
        str[--len] = stk.top();
        stk.pop();
    }
    cout << str << "\n";
}
 
void InputData() {
    cin >> N >> K;
    cin >> str;
}
 
int main() {
    InputData();//입력 받는 부분
 
    Solve();//여기서부터 작성
 
    return 0;
}
/**************************************************************
    Problem: 6043
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:2840 kb
****************************************************************/