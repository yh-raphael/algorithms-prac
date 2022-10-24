#define onlycc ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <iostream>
using namespace std;

int T, C;

int main(void)
{
    onlycc;
    cin >> T;

	while (T--)
	{
		cin >> C;
		cout << C / 25 << ' ';
		C %= 25;
		cout << C / 10 << ' ';
		C %= 10;
		cout << C / 5 << ' ';
		C %= 5;
		cout << C << '\n';
	}

    return 0;
}