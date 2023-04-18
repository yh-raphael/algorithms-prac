#include <iostream>
using namespace std;

int N, M;
int A[10000] = { 0,};

int main (void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int start = 0;
    int end = 0;
    int tmp = A[0];
    int cnt = 0;

    while (1) {
        if (start > N-1) break;
        if (end > N) break;
        if (tmp == M) {
            cnt ++;
            tmp -= A[start ++];
        }
        else if (tmp < M) {
            tmp += A[++ end];
        }
        else if (tmp > M) {
            tmp -= A[start ++];
        }
    }

    cout << cnt << '\n';
    return 0;
}