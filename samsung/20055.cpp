#include <iostream>
#include <deque>
using namespace std;

int N, K;
int A[201];
deque <int> DQ;             // conveyor belt parts.
deque <int> robot_list;     // index: robot's order, element: robot's position.
int cnt = 0;

void print_debug (void)
{
    cout << endl;
    for (int i = 0; i <= 2*N - 1; i++) {
        cout << DQ[i] << ' ';
    } cout << endl;
    for (unsigned int i = 0; i < robot_list.size (); i++) {
        cout << robot_list[i];
    } cout << endl;

    return;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);
    cin >> N >> K;
    int tmp;
    for (int i = 0; i <= 2*N - 1; i++) {
        cin >> tmp;
        DQ.push_back (tmp);
    }
    
    int num_zero = 0;
    while (true)
    {
        cnt ++; //cout << "=== cnt: " << cnt << endl;
        // (1) rotate.
        int tmp = DQ.back ();
        DQ.pop_back ();
        DQ.push_front (tmp);
        for (unsigned int i = 0; i < robot_list.size (); i++) {
            robot_list[i] ++;
        }
        // 맨 앞 로봇 위치가 N-1 이면 즉시 out.
        if (!robot_list.empty () && robot_list[0] == N-1) {
            robot_list.pop_front ();
        }
        // print_debug ();
        
        // (2) robot move.
        if (robot_list.empty () == false) {
            for (unsigned int i = 0; i < robot_list.size (); i++) {
                if (i != 0 && robot_list[i-1] == robot_list[i] + 1) continue;
                if (DQ[robot_list[i] + 1] == 0) continue;
                robot_list[i] ++;           // 한 칸 이동.
                DQ[robot_list[i]] --;       // 내구도 즉시 1 감소.
                if (DQ[robot_list[i]] == 0) {
                    num_zero ++;
                }
            }
        }
        // 맨 앞 로봇 위치가 N-1 이면 즉시 out.
        if (!robot_list.empty () && robot_list[0] == N-1) {
            robot_list.pop_front ();
        }
        // print_debug ();
        
        // (3) put a new robot.
        if (DQ[0] != 0) {
            robot_list.push_back (0);   // 0번 위치에 올림.
            DQ[0] --;                   // 내구도 1 감소.
            if (DQ[0] == 0) {
                num_zero ++;
            }
        }
        // print_debug ();

        // (4) escape check.
        if (num_zero >= K) {
            break;
        }
    }

    // print_debug();
    cout << cnt << '\n';
    return 0;
}