#include <iostream>
#include <stack>
using namespace std;
#define MAXN ((int)1e5)

int N;//빌딩수
int H[MAXN+10];//빌딩높이
int sol[MAXN+10];//각 빌딩에서 보이는 빌딩 번호
stack<int> stk;

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
void Solve()
{
    for (int i=1; i<=N; i++) {
        while (!stk.empty() && H[i] > H[stk.top()]) {
            sol[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력받는 부분

	//여기서부터 작성
    Solve();

	OutputData();//출력하는 부분
	return 0;
}