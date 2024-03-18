#include <iostream>
#include <vector>
using namespace std;

int N, P;
vector<int> V;

int Step(int num)
{
    num *= N;
    num %= P;
    return num;
}
int Solve()
{
    int sol = -2;
    int num = N; V.push_back(num);
    while (1) {
        num = Step(num);
        for (int i=0; i<V.size(); i++) {
            if (num == V[i]) {
                sol = V.size() - i;
                return sol;
            }
        }
        V.push_back(num);
    }
    return sol; // 도달 불가능?
}

void InputData(){
    cin >> N >> P;
}
int main(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}