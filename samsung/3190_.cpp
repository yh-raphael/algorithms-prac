#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main (void)
{
    // map info.
    int map[102][102] = { 0, };
    bool visit[102][102] = { false, };
    int N; cin >> N;
    int K; cin >> K;
    int row, col;
    for (int i = 0; i < K; i++) {
        cin >> row >> col;
        map[row - 1][col - 1] = 1;
    }

    // snake info.
    int x = 0, y = 0;
    int dir = 0;
    int dy[4] = {0, 1, 0, -1};  // 우, 하, 좌, 상
    int dx[4] = {1, 0, -1, 0};

    queue <pair <int, int> > Q;
    Q.push (make_pair (x, y));

    // game info.
    int count = 0;
    int number[101]; char direction[101];
    int L; cin >> L;
    for (int i = 0; i < L; i++)
        cin >> number[i] >> direction[i];

    for (int i = 0; i < L; i++)
    {
        while (count < number[i] || i == L - 1)
        {
            count ++;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[ny][nx]) {
                if (map[ny][nx] == 1) {
                    map[ny][nx] = 0;
                    Q.push (make_pair (nx, ny));
                    visit[ny][nx] = true;
                }
                else {
                    Q.push (make_pair (nx, ny));
                    visit[ny][nx] = true;
                    visit[Q.front ().second][Q.front ().first] = false;
                    Q.pop ();
                }
            }
            else {
                cout << count << '\n';
                return 0;
            }
            x = nx; y = ny;
            if (count == number[i]) {
                // 와... 이게 ㄹㅇ 기발하구나!
                if (direction[i] == 'D')   // 우회전
                    dir = (dir + 1) % 4;
                else                    // 좌회전
                    dir = (dir + 3) % 4;
            }
        }
    }
    return 0;
}