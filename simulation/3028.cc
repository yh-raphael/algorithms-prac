#include <iostream>
#include <string>

using namespace std;

int arr[3] = {1, 0, 0};

void swap (int x, int y)
{
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

int main (void)
{
    
    string str;
    cin >> str;

    for (int i = 0; i < str.length (); i++)
    {
        if (str[i] == 'A')
        {
            swap (0, 1);
        }
        else if (str[i] == 'B')
        {
            swap (1, 2);
        }
        else if (str[i] == 'C')
        {
            swap (0, 2);
        }
    }
    
    // cout << str.length() << '\n';
    // cout << str;

    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] == 1)
        {
            result = i + 1;
        }
    }
    cout << result << '\n';
    return 0;
}