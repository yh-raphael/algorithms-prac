// Written by Raphael on 2023-02-13-Mon.
#include <iostream>

using namespace std;

int main (void)
{
    int N; cin >> N;
    int store[1001];
    for (int i = 1; i <= N; i++)
        cin >> store[i];

    int count = 0;
    int cur = 0;
    for (int i = 1; i <= N; i++)
    {
        if (cur == 0) {
            if (store[i] == 0) {
                count ++;
                cur = 1;
            }
            continue;
        }
        else if (cur == 1) {
            if (store[i] == 1) {
                count ++;
                cur = 2;
            }
            continue;
        }
        else if (cur == 2) {
            if (store[i] == 2) {
                count ++;
                cur = 0;
            }
            continue;
        }
    }

    cout << count << '\n';
    return 0;
}