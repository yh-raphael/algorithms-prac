#include <iostream>
#include <algorithm>    // max ().
using namespace std;

int N;
int arr[301];   // index: [1~300]
int dp[301];    // 동적 계획법을 통해 ascending order로 계산한 실시간 결과들(최댓값).
void print_dp () {
    for (int i = 1; i <=N; i++) {
        cout << dp[i] << ' ';
    }   cout << endl;
}   // for DEBUG

void input (void)
{
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

void solve (void)
{
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max (arr[1] + arr[3], arr[2] + arr[3]);

    for (int i = 4; i <= N; i++)
    {
        dp[i] = max (dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
        // print_dp ();
    }
}

int main (void)
{
    cin >> N;
    input ();
    solve ();
    cout << dp[N] << '\n';
    return 0;
}