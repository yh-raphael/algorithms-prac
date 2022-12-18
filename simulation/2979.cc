#include <iostream>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    // PRICE.
    int A, B, C;
    cin >> A >> B >> C;
    
    // IN,OUT TIME.
    int arr[101] = {0, };
    int c1_in, c1_out;
    int c2_in, c2_out;
    int c3_in, c3_out;

    cin >> c1_in >> c1_out;
    cin >> c2_in >> c2_out;
    cin >> c3_in >> c3_out;
    for (int i = 1; i <= 100; i++)
    {
        if (c1_in <= i && i < c1_out)
            arr[i] ++;
        if (c2_in <= i && i < c2_out)
            arr[i] ++;
        if (c3_in <= i && i < c3_out)
            arr[i] ++;
    }

    // RESULT.
    int result = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (arr[i] == 0) continue;
        else if (arr[i] == 1) {
            result += A;
        }
        else if (arr[i] == 2) {
            result += B * 2;
        }
        else if (arr[i] == 3) {
            result += C * 3;
        }
    }

    cout << result << '\n';
    return 0;
}