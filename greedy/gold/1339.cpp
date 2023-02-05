// Written by Raphael on 2023-02-06-Mon.
#include <iostream>
#include <string>       // string input; cin >> input; int j = input.length();
#include <algorithm>    // sort (num_alph, num_alph + 26, greater <int> ());
using namespace std;

// 0: A, 1: B ... 25: Z
int num_alph[26] = { 0, };

bool cmp_func (int a, int b)
{
    return (a > b);
}

int main (void)
{
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input; cin >> input;
        int pow = 1;
        for (int j = input.length () - 1; j >= 0; j--)
        {
            num_alph[input[j] - 'A'] += pow;
            pow *= 10;
        }
    }

    // sort (num_alph, num_alph + 26, cmp_func);
    sort (num_alph, num_alph + 26, greater <int> ());

    // for (int i = 0; i < 26; i++)
    //     cout << num_alph[i] << ' ';
    // cout << '\n';

    int num = 9;
    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        if (num_alph[i] == 0)
            break;
        result += num_alph[i] * num;
        num --;
    }

    cout << result << '\n';
    return 0;
}