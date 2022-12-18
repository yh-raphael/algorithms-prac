// Written by Raphael on 2022-12-18-Sun.
#include <iostream>
using namespace std;

int main (void)
{
    // ios_base::sync_with_stdio (0);
    // cin.tie (0); cout.tie (0);

    // 이런 방식 처음 봄!
    cin.tie (0) -> sync_with_stdio(0);

    // PRICE - [1]: A, [2]: B, [3]: C, index -> num_car.
    int price[4] = {0, };
    for (int i = 1; i < 4; i++)
        cin >> price[i];
    
    // NUM_CAR, index -> timestamp.
    int num_car[101] = {0, };
    // IN,OUT TIME -> itereate 3 times.
    for (int i = 0; i < 3; i++)
    {
        int in, out;
        cin >> in >> out;
        // build NUM_CAR
        for (int j = in; j < out; j++)
            num_car[j] ++;
    }

    // RESULT.
    int result = 0;
    for (int i = 1; i <= 100; i++)
    {
        result += price[num_car[i]] * num_car[i];
    }

    cout << result << '\n';
    return 0;
}