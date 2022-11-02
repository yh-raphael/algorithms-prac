// 거스름돈

#include <iostream>
using namespace std;

int N;
int re = 0;

int main(void)
{
    cin >> N;
    N = 1000 - N;

    re += N / 500; N = N % 500;
    re += N / 100; N = N % 100;
    re += N / 50; N = N % 50;
    re += N / 10; N = N % 10;
    re += N / 5; N = N % 5;
    re += N;

    cout << re << '\n';
    return 0;
}