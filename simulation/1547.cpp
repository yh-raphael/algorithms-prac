#include <iostream>
//#include <algorithm>
using namespace std;

int main (void)
{
	int arr[4] = {0, 1, 2, 3};
	int M; cin >> M;

	while (M--)
	{
		int X, Y;
		cin >> X >> Y;
		swap (arr[X], arr[Y]);
	}

	for (int i = 0; i < 4; i++)
	{
		if (arr[i] == 1) {
			cout << i << '\n';
			break;
		}
	}

    return 0;
}