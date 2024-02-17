#include <iostream>
#include <stack>
using namespace std;

#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];

stack<int> S;

void InputData(){
	cin >> N;
	cin >> M[0];
	for(int i=1; i<N; i++){
		cin >> op[i] >> M[i];
	}
}

int Solve()
{
    S.push(M[0]);
    for (int i=1; i<N; i++) {
        if (op[i] == '+') {
            S.push(M[i]);
        }
        else if (op[i] == '-') {
            S.push(M[i] * (-1));
        }
        else if (op[i] == '*') {
            int tmp = S.top() * M[i];
            S.pop();
            S.push(tmp);
        }
        else if (op[i] == '/') {
            int tmp = S.top() / M[i];
            S.pop();
            S.push(tmp);
        }
    }

    int sum = 0;
    while (!S.empty()){
        sum += S.top();
        S.pop();
    }
    return sum;
}

int main(){
	int ans = -1;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력

	//여기서부터 작성
    ans = Solve();

	cout << ans << "\n";

	return 0;
}