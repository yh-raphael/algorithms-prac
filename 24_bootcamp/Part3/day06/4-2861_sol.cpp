#include <iostream>
#include <stack>
using namespace std;
int N;//히스토그램수
int H[100000 + 10];//히스토그램 높이
struct STK {
    int h, n;//높이, 시작 인덱스
};
long long Solve() {
    long long maxarea = 0;
    stack <STK> stk = {};//직사각형을 그릴수있는 정보만 저장
    for (int i = 0; i < N; i++) {
        //top이 높으면 제거(넓이 계산, 시작 인덱스 뺏어오기) ==> 주의, 여러개가 제거될수있음
        int n = i;//pop시키면 그 위치로 변경(아니면, 자기 인덱스)
        while (!stk.empty() && (stk.top().h > H[i])) {
            n = stk.top().n;//시작 인덱스 뺏어오기
            long long area = (long long)stk.top().h * (i - stk.top().n);
            if (maxarea < area) maxarea = area;
            stk.pop();
        }
        //i번째 요소 저장하기
        if (!stk.empty() && stk.top().h == H[i]) continue;
        stk.push({ H[i], n });
    }
    while (!stk.empty()) {
        long long area = (long long)stk.top().h * (N - stk.top().n);
        if (maxarea < area) maxarea = area;
        stk.pop();
    }
    return maxarea;
}
bool InputData() {
    cin >> N;
    if (N == 0) return false;
   
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    return true;
}
   
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
   
    long long ans = -1;
    while (InputData()) {//입력받는 부분
   
        ans = Solve();//여기서부터 작성
   
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}
/**************************************************************
    Problem: 2861
    Language: C++
    Result: Accepted
    Time:37 ms
    Memory:2768 kb
****************************************************************/