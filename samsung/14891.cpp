#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque <int> gear[4];
int CMD[100][2] = { 0, };   // command: 0,1,2, ...
int rot_dir[4] = { 0, };

void move_gear (int gear_num, int direction)
{
    if (direction == -1) {
        int tmp = gear[gear_num].front ();
        gear[gear_num].pop_front ();
        gear[gear_num].push_back (tmp);
    }
    else if (direction == 1) {
        int tmp = gear[gear_num].back ();
        gear[gear_num].pop_back ();
        gear[gear_num].push_front (tmp);
    }
}

// rotation direction array init!
void init ()
{
    for (int i = 0; i < 4; i++)
        rot_dir[i] = 0;
}

// Recursive check!
void left_check (int gear_num, int direction)
{
    if (gear_num <= 0)
        return;
    if (gear[gear_num - 1][2] != gear[gear_num][6]) {
        rot_dir[gear_num - 1] = direction * -1;
        left_check (gear_num - 1, direction * -1);
    }
}

// Recursive check!
void right_check (int gear_num, int direction)
{
    if (gear_num >= 3)
        return;
    if (gear[gear_num][2] != gear[gear_num + 1][6]) {
        rot_dir[gear_num + 1] = direction * -1;
        right_check (gear_num + 1, direction * -1);
    }   
}

void solve (int gear_num, int direction)
{
    rot_dir[gear_num] = direction;
    left_check (gear_num, direction);
    right_check (gear_num, direction);

    for (int i = 0; i < 4; i++)
        move_gear (i, rot_dir[i]);
}

int main (void)
{
    char n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> n;
            gear[i].push_back (n - '0');
        }
    }
    int K; cin >> K;
    int g, d;
    for (int i = 0; i < K; i++)
        cin >> CMD[i][0] >> CMD[i][1];

    // solve.
    for (int i = 0; i < K; i++)
    {
        init ();
        solve (CMD[i][0] - 1, CMD[i][1]);
    }

    // calculate result.
    int result = 0;
    int mul = 1;
    for (int i = 0; i < 4; i++)
    {
        result += gear[i][0] * mul;
        mul *= 2;
    }

    cout << result << '\n';
    return 0;    
}