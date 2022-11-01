#include <iostream>

using namespace std;

int main()
{
    int M, N;
    int sum = 0;
    int min = 10001;
    
    cin >> M >> N;

    for (int i=1; i<=100; i++)
    {
        if (M <= i*i && i*i <= N) {
            sum += i*i;
            if (i*i < min)
                min = i*i;
        }
    }

    if (sum != 0)    
        cout << sum << endl << min << endl;
    else
        cout << "-1" << endl;

    return 0;
}