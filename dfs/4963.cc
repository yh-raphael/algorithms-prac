#include <iostream>
#include <cstring>

using namespace std;

bool map[51][51] = { 0, };
bool isVisited[51][51] = { 0, };

int dh[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dw[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int W, H; 

void dfs (int h, int w)
{
    isVisited[h][w] = true;

    for (int i = 0; i < 8; i++)
    {
        if (h + dh[i] >= 1 && h + dh[i] <= H && w + dw[i] >= 1 && w + dw[i] <= W && map[h + dh[i]][w + dw[i]] == 1 && isVisited[h + dh[i]][w + dw[i]] == false)
        {
            dfs (h + dh[i], w + dw[i]);
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (NULL); cout.tie (NULL);

    int cnt = 0;

    while (1)
    {
        cin >> W >> H;
        if (W == 0 && H == 0)
            break;

        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (map[i][j] == 1 && isVisited[i][j] == false) {
                    dfs (i, j);
                    cnt ++;
                }
            }
        }

        cout << cnt << '\n';

        memset (map, 0, sizeof(map));
        memset (isVisited, 0, sizeof(isVisited));
        cnt = 0;
    }

    return 0;
}