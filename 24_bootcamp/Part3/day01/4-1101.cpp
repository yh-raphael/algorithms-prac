#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;
int used[MAXN];

int Step(int num)
{
    int val = 0;
    while (num) {
        int tmp = num % 10;
        val += tmp * tmp;
        num /= 10;
    }
    return val;
}
bool isHappyNum(int num)
{
    used[num] = 1;
    for (int i=2; ; i++) {
        num = Step(num);
        if (num == 1) return true;
        if (used[num]) break;
        used[num] = i;
    }
    return false;
}
int Solve()
{
    int sol = -2;
    for (int i=N; i>0; i--) {
        if (isHappyNum(i)) {
            sol = i;
            break;
        }
    }
    return sol;
}

void InputData(){
    cin >> N;
}
int main(){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = Solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}