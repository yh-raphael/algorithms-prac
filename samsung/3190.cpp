#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

bool map_snake[101][101] = { 0, };
bool map_apple[101][101] = { 0, };
int turn_time[101] = {0, };        // index: order, element: time_slot

int main (void)
{
    int N; cin >> N;
    int K; cin >> K;
    vector <pair <int, int> > apple;
    for (int i = 0; i < K; i++) {
        int row, col; cin >> row >> col;
        apple.push_back (make_pair (row, col));
    }
    int L; cin >> L;
    vector <pair <int, char> > turn;
    for (int i = 0; i < L; i++) {
        int X; cin >> X;
        char C; cin >> C;
        turn.push_back (make_pair (X, C));
    }

    // apple marking.
    for (int i = 0; i < K; i++)
        map_apple[apple[i].first][apple[i].second] = true;

    // time marking.
    for (int i = 0; i < L; i++)
        turn_time[i] = turn[i].first;

    // simulation start!
    int time = 0;
    int next_turn_time = turn_time[0];
    int head_x = 1, head_y = 1;         // pair <int, int> head = make_pair (1, 1);
    queue <pair <int, int> > Q_snake;

    while (1)
    {
        if (head_x < 1 || head_x > N || head_y < 1 || head_y > N)
            break;
        for (int i = 0; i < Q_snake.size(); i++)
        {
            if (head_x == Q_snake.)
        }
    }
    
    return 0;
}