    #include <iostream>
    #include <algorithm>
    using namespace std;

    int N;
    int A[10001] = { 0, };
    int dp[10001] = { 0, };

    void dp_solve (void)
    {
        dp[0] = 0;
        dp[1] = A[1];
        dp[2] = A[1] + A[2];
        //dp[3] = max (A[1] + A[3], A[2] + A[3]);
        for (int i = 3; i <= N; i++) {
            int tmp = max (dp[i-1], dp[i-2] + A[i]);
            dp[i] = max (tmp, dp[i-3] + A[i-1] + A[i]);
        }
    }

    int main (void)
    {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }

        dp_solve ();
        // for (int i = 1; i <= N; i++) {
        //     cout << dp[i] << ' ';
        // }   cout << endl;

        // int result = max (dp[N-3], dp[N-2]);
        // result = max (dp[N-2], dp[N-1]);
        cout << dp[N] << '\n';
        return 0;
    }