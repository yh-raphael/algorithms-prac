#include <iostream>
using namespace std;
#define MAXN ((int)1e3)

int N;//정수개수
int A[MAXN + 10];//입력 정수

int MakeDigitRoot(int num)
{
    int val = 0;
    int k = 10;
    while (num) {
        val += num % k;
        num /= k;
    }
    if (val > 9) {
        val = MakeDigitRoot(val);
    }
    return val;
}
int Solve()
{
    int dr = -1;
    int sol = 1e6;
    for (int i=0; i<N; i++) {
        int tmp = MakeDigitRoot(A[i]);
        if (dr < tmp || (dr == tmp && sol > A[i])) {
            dr = tmp;
            sol = A[i];
        }
    }
    return sol;
}

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}
int main(){
    int ans = -1;
    InputData();//입력 받는 부분

    //여기서부터 작성
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}