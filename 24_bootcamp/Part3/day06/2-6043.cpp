#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
#define MAXN ((int)5e5)
int N, K;
char str[MAXN + 10];
stack<char> ST;
 
void InputData() {
    cin >> N >> K;
    cin >> str;
}
 
void Solve()
{
    int stop_idx = -1;
    ST.push(str[0]);
    for (int i=1; str[i]; i++) {
        char cur = str[i];
        // Stack operation.
        while (!ST.empty() && K) {
            if (ST.top() < cur) {
                ST.pop(); K--;
            }
            else {
                break;
            }
        }
        ST.push(cur);
        if (K == 0) {
            stop_idx = i;
            break;
        }
    }
    // K개 다 처리한 경우!
    if (K == 0) {
        string s = "";
        while (!ST.empty()) {
            char ch = ST.top(); ST.pop();
            s = ch + s;
        }
        cout << s;
        // 마저 찍기!
        for (int i=stop_idx+1; str[i]; i++) {
            cout << str[i];
        }
    }
    else {
        // 뒤에거 버리기
        while (K--) {       // gooooooooooood!
        // for (int i=0; i<K; i++) {
            ST.pop();
        }
        // string s = "";
        // while (!ST.empty()) {
        //     char ch = ST.top(); ST.pop();
        //     s = ch + s;
        // }
        // cout << s;
        int len = ST.size();        // gooooooooooooooooooooood!
        str[len] = 0;
        while (!ST.empty()) {
            char ch = ST.top(); ST.pop();
            str[--len] = ch;
        }
        cout << str;
    }
    cout << endl;
}
 
int main() {
    InputData();//입력 받는 부분
 
    //여기서부터 작성
    Solve();
 
    return 0;
}