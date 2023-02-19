// How to check duplicate alphabet start point?
#include <iostream>
#include <cstring>
using namespace std;

int main (void)
{
    int N; cin >> N;
    bool alph[26] = { 0, };

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        memset (alph, 0, 26);
        string input; cin >> input;

        int isGroup = 1;
        alph[input[0] - 'a'] = 1;   // first mark.
        for (unsigned int j = 1; j < input.length (); j++)
        {
            if (input[j] == input [j - 1])
                continue;
            else {  // non-contiguous element.
                if (alph[input[j] - 'a'] == 1) {
                    isGroup = 0;
                    break;
                }
                else
                    alph[input[j] - 'a'] = 1;       // subsequent mark.
            }
        }
        result += isGroup;
    }

    cout << result << '\n';
    return 0;
}