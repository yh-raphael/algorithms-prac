#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;//장기판 행의 수, 열의 수
int kr, kc, sr, sc;//말 행과 열, 졸 행과 열

#define MAXN (100)
bool visited[MAXN+10][MAXN+10];
typedef struct state{
    int r, c, t;
} ST;
queue<ST> Q;

int BFS()
{
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};

    ST start; start.r=kr; start.c=kc; start.t=0;
    Q.push(start); visited[kr][kc] = true;
    while (!Q.empty()) {
        ST cur = Q.front(); Q.pop();

        if (cur.r==sr && cur.c==sc) return cur.t;

        for (int i=0; i<8; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr<1 || nr>R || nc<1 || nc>C) continue;
            if (visited[nr][nc]) continue;

            ST next; next.r=nr; next.c=nc; next.t=cur.t+1;
            Q.push(next); visited[nr][nc] = true;
        }
    }
    return -2;
}

void InputData(){
	cin >> R >> C;
	cin >> kr >> kc >> sr >> sc;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력

	//여기서부터 작성
    ans = BFS();

	cout << ans << "\n";//출력
	return 0;
}