#include <iostream>

using namespace std;

int A[51][51];
int B[51][51];
int R, C, T;
int pos1, pos2;
int result = 0;

void copy_map ()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            B[i][j] = A[i][j];
        }
    }
}

void diffuse ()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            // fine dust exists.
            if (B[i][j] > 0) {
                if (i == 1 && j == 1) {
                    A[i+1][j] += B[i][j] / 5;
                    A[i][j+1] += B[i][j] / 5;
                    A[i][j] -= 2 * (B[i][j] / 5);
                }
                else if (i == 1 && j == C) {
                    A[i+1][j] += B[i][j] / 5;
                    A[i][j-1] += B[i][j] / 5;
                    A[i][j] -= 2 * (B[i][j] / 5);
                }
                else if (i == R && j == 1) {
                    A[i-1][j] += B[i][j] / 5;
                    A[i][j+1] += B[i][j] / 5;
                    A[i][j] -= 2 * (B[i][j] / 5);
                }
                else if (i == R && j == C) {
                    A[i-1][j] += B[i][j] / 5;
                    A[i][j-1] += B[i][j] / 5;
                    A[i][j] -= 2 * (B[i][j] / 5);
                }
                else if (i == 1 && j != 1 && j != C) {
                    A[i+1][j] += B[i][j] / 5;
                    A[i][j+1] += B[i][j] / 5;
                    A[i][j-1] += B[i][j] / 5;
                    A[i][j] -= 3 * (B[i][j] / 5);
                }
                else if (i == R && j != 1 && j != C) {
                    A[i-1][j] += B[i][j] / 5;
                    A[i][j-1] += B[i][j] / 5;
                    A[i][j+1] += B[i][j] / 5;
                    A[i][j] -= 3 * (B[i][j] / 5);
                }
                else if (i != 1 && i != R && j == 1) {
                    // cleaner boundary.
                    if (i == pos1 - 1 && j == 1) {
                        A[i-1][j] += B[i][j] / 5;
                        A[i][j+1] += B[i][j] / 5;
                        A[i][j] -= 2 * (B[i][j] / 5);
                        continue;
                    }
                    if (i == pos2 + 1 && j == 1) {
                        A[i+1][j] += B[i][j] / 5;
                        A[i][j+1] += B[i][j] / 5;
                        A[i][j] -= 2 * (B[i][j] / 5);
                        continue;
                    }
                    A[i-1][j] += B[i][j] / 5;
                    A[i+1][j] += B[i][j] / 5;
                    A[i][j+1] += B[i][j] / 5;
                    A[i][j] -= 3 * (B[i][j] / 5);
                }
                else if (i != 1 && i != R && j == C) {
                    A[i-1][j] += B[i][j] / 5;
                    A[i+1][j] += B[i][j] / 5;
                    A[i][j-1] += B[i][j] / 5;
                    A[i][j] -= 3 * (B[i][j] / 5);
                }
                else {
                    // cleaner boundary.
                    if (i == pos1 && j == 2) {
                        A[i-1][j] += B[i][j] / 5;
                        A[i+1][j] += B[i][j] / 5;
                        A[i][j+1] += B[i][j] / 5;
                        A[i][j] -= 3 * (B[i][j] / 5);
                        continue;
                    }
                    if (i == pos2 && j == 2) {
                        A[i-1][j] += B[i][j] / 5;
                        A[i+1][j] += B[i][j] / 5;
                        A[i][j+1] += B[i][j] / 5;
                        A[i][j] -= 3 * (B[i][j] / 5);
                        continue;
                    }
                    A[i-1][j] += B[i][j] / 5;
                    A[i+1][j] += B[i][j] / 5;
                    A[i][j+1] += B[i][j] / 5;
                    A[i][j-1] += B[i][j] / 5;
                    A[i][j] -= 4 * (B[i][j] / 5);
                }
            }// fine dust exists.
        }
    }
}

void purify ()
{
    // upper part.
    for (int i = pos1-1; i >= 2; i--) {
        A[i][1] = A[i-1][1];
    }
    for (int j = 1; j <= C-1; j++) {
        A[1][j] = A[1][j+1];
    }
    for (int i = 1; i <= pos1-1; i++) {
        A[i][C] = A[i+1][C];
    }
    for (int j = C; j >= 3; j--) {
        A[pos1][j] = A[pos1][j-1];
    }
    A[pos1][2] = 0;

    // down part.
    for (int i = pos2+1; i <= R-1; i++) {
        A[i][1] = A[i+1][1];
    }
    for (int j = 1; j <= C-1; j++) {
        A[R][j] = A[R][j+1];
    }
    for (int i = R; i >= pos2+1; i--) {
        A[i][C] = A[i-1][C];
    }
    for (int j = C; j >= 3; j--) {
        A[pos2][j] = A[pos2][j-1];
    }
    A[pos2][2] = 0;
}

void count_dust ()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (A[i][j] > 0)
                result += A[i][j];
        }
    }
}

int main (void)
{
    cin >> R >> C >> T;
    int cnt = 0;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == -1) {
                if (cnt == 0) {
                    pos1 = i;
                    cnt ++;
                }
                else if (cnt == 1) {
                    pos2 = i;
                }
            }
        }
    }

    // cout << endl;
    // cout << pos1 << ' ' << pos2 << endl;

    for (int i = 0; i < T; i ++)
    {
        // copy.
        copy_map ();

        // diffuse.
        diffuse ();

        // purify.
        purify ();
    }

    // cout << endl;
    // for (int i = 1; i <= R; i++) {
    //     for (int j = 1; j <= C; j++) {
    //         cout << A[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // count dust.
    count_dust ();

    cout << result << '\n';
    return 0;
}