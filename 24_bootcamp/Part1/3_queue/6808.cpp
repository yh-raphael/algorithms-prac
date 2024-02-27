#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int N, M;//문서수, 궁금한 문서 번호
int P[MAXN+10];//문서 우선순위

typedef struct doc{
    int n, p;
} DOC;

int Solve()
{
    //0. 초기화.
    int sol = 0;
    int priocnt[10] = {0};
    queue<DOC> que;
    
    //1. 우선순위별 개수 파악, 큐에 저장.
    for (int i=0; i<N; i++) {
        priocnt[P[i]]++;    // 이 count가 핵심!
        DOC tmp; tmp.n=i, tmp.p=P[i];
        que.push(tmp);
    }
    //2. 시뮬레이션
    for (int p=9; p>=1; p--) {
        while (priocnt[p]) {
            DOC cur = que.front(); que.pop();
            if (cur.p == p) {
                sol++;
                if (cur.n == M) return sol;
                priocnt[p]--;
            }
            else {
                que.push(cur);
            }
        }
    }
    return -2;  // 여기까지 도달 불가능!
}

void InputData() {
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> P[i];
    }
}

int main() {
    int ans = -1;
    int T;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        ans = Solve();

        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}