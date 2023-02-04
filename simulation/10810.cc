#include <iostream>
using namespace std;

int arr[101] = { 0, };

int main (void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int I, J, K;
        cin >> I >> J >> K;
        
        for (int j = I; j <= J; j++)
        {
            arr[j] = K;
        }
    }
    for (int i = 1; i <= N; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}