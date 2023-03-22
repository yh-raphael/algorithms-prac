#include <iostream>
#include <algorithm>    // max (result, check_two ()).
using namespace std;

int N, M;
int map[501][501] = { 0, };
int result = 0;

void print_debug ()
{
    cout << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

// [1] rectangle.
int check_one ()
{
    int max_sum = 0;
    int sum = 0;
    // horizontal.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M-3; j++) {
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
            max_sum = max (max_sum, sum);
        }
    }
    // vertical.
    for (int i = 1; i <= N-3; i++) {
        for (int j = 1; j <= M; j++) {
            sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
            max_sum = max (max_sum, sum);
        }
    }
    return max_sum;
}

// [2] square.
int check_two ()
{
    int max_sum = 0;
    int sum = 0;
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    return max_sum;
}

// [3] _ _ _ |
int check_three ()
{
    int max_sum = 0;
    int sum = 0;
    // (1)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    // (2)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+2];
            max_sum = max (max_sum, sum);
        }
    }
    // (3)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    // (4)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j];
            max_sum = max (max_sum, sum);
        }
    }
    // (5)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+2][j];
            max_sum = max (max_sum, sum);
        }
    }
    // (6)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j];
            max_sum = max (max_sum, sum);
        }
    }
    // (7)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j+1] + map[i][j] + map[i+1][j] + map[i+2][j];
            max_sum = max (max_sum, sum);
        }
    }
    // (8)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
            max_sum = max (max_sum, sum);
        }
    }
    return max_sum;
}

// [4]
int check_four ()
{
    int max_sum = 0;
    int sum = 0;
    // (1)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    // (2)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i+1][j] + map[i+1][j+1] + map[i][j+1] + map[i][j+2];
            max_sum = max (max_sum, sum);
        }
    }
    // (3)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i+1][j] + map[i+2][j] + map[i][j+1] + map[i+1][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    // (4)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
            max_sum = max (max_sum, sum);
        }
    }
    return max_sum;
}

// [5]
int check_five ()
{
    int max_sum = 0;
    int sum = 0;
    // (1)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    // (2)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    // (3)
    for (int i = 1; i <= N-1; i++) {
        for (int j = 1; j <= M-2; j++) {
            sum = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+1];
            max_sum = max (max_sum, sum);
        }
    }
    // (4)
    for (int i = 1; i <= N-2; i++) {
        for (int j = 1; j <= M-1; j++) {
            sum = map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+1][j];
            max_sum = max (max_sum, sum);
        }
    }
    return max_sum;
}

int main (void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
    // print_debug ();
    result = max (result, check_one ());        // [1] rectangle.
    result = max (result, check_two ());        // [2] square.
    result = max (result, check_three ());      // [3] _ _ _ |
    result = max (result, check_four ());       // [4] |_ _
                                                //         |
    result = max (result, check_five ());       // [5] hat.

    cout << result << '\n';
    return 0;
}