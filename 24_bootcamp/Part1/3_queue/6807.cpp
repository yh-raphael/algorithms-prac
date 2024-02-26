#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int N;
int sol[MAXN + 10];
queue<int> que;

void InputData(){
	cin >> N;
}

void OutputData(){
	for (int i=0; i<N; i++){
		cout << sol[i] << "\n";
	}
}

void Sol()
{
    int wp = 0;
    
    for (int i=1; i<=N; i++) {
        que.push(i);
    }

    for (int i=1; i<=N-1; i++) {
        int cnt = que.back() / 2;
        for (int j=1; j<=cnt; j++) {
            que.push(que.front());
            que.pop();
        }
        sol[wp++] = que.front();
        que.pop();
    }
    sol[wp] = que.front();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력
	Sol();//여기서부터 작성
	OutputData();//출력
	return 0;
}