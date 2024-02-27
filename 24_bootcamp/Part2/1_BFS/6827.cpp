#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int C, R;//가로, 세로 크기
int sc, sr, ec, er;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보

bool visited[MAXN+10][MAXN+10];
typedef struct state{
    int r, c, t; 
} ST;
queue<ST> Q;

int Solve()
{
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    ST tmp; tmp.r=sr; tmp.c=sc; tmp.t=0;
    Q.push(tmp); visited[sr][sc] = true;

    while (!Q.empty()) {
        ST cur = Q.front(); Q.pop();
        if ((cur.r == er) && (cur.c == ec)) return cur.t;

        for (int i=0; i<4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (map[nr][nc] != '0') continue;
            if (visited[nr][nc]) continue;

            ST next; next.r=nr; next.c=nc; next.t=cur.t+1;
            Q.push (next); visited[nr][nc] = true;
        }
    }
    return -2;
}

void InputData(){
	cin >> C >> R;
	cin >> sc >> sr >> ec >> er;
	for (int i=1; i<=R; i++){
		cin >> &map[i][1];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력

	//여기서부터 작성
    ans = Solve();

	cout << ans << "\n";//출력
	return 0;
}