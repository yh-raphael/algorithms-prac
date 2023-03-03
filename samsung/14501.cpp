#include <iostream>
#include <algorithm>    //   dp[i] = max (max_pay, dp[i]);
// #include <bits/stdc++.h>

using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);

    int T[16];
    int P[16];
    int dp[17] = { 0, };
    int N; cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    // int N; cin >> N;
    // int *T = new int [N + 1];
    // int *P = new int [N + 1];
    // int *dp = new int [N + 2];
    // fill (dp, dp + N + 2, 0);
    // for (int i = 1; i <= N; i++)
    //     cin >> T[i] >> P[i];

    int max_pay = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        dp[i] = max (max_pay, dp[i]);   // '0'인 경우 (쉬는 경우) update!! -> 테케 #4!
        if (i <= N && i + T[i] <= N + 1) {
            dp[i + T[i]] = max (dp[i + T[i]], dp[i] + P[i]);    // dp[i + T[i]] => 그날까지 뛰었을 때 최대로 벌 수 있는 수익을 항상 저장하고 있음.
        }
        max_pay = max (max_pay, dp[i]); // 정답은 바로바로 save.
    }

    // free (T); free (P); free (dp);

    cout << max_pay << '\n';
    return 0;
}