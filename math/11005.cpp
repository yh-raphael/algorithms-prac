#include <iostream>
#include <climits>
#include <stack>
using namespace std;

//long N;
int N;
int B;

int A[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main (void)
{
    cin >> N >> B;
    // cout << (char)A[2] << endl;

    stack <int> ST;
    int div = N;
    int rem;
    while (true)
    {
        int tmp = div;
        div = (div / B);
        rem = (tmp % B);
        ST.push (rem);
        if (div == 0) break;
    }
    while (!ST.empty())
    {
        int t = ST.top();
        if (t < 10)
            cout << t;
        else {
            cout << (char)A[t-10];
        }

        ST.pop();
    }
    cout << endl;
    return 0;
}