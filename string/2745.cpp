#include <iostream>
#include <cstring>
using namespace std;

string str;
int B;

int main (void)
{
    cin >> str >> B;
    
    int result = 0;
    int m = 1;
    for (int i = str.length() - 1; i >= 0; i--) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            result += m * (str[i] - 'A' + 10);
        }
        else {
            result += m * (str[i] - '0');
        }
        m *= B;
    }
    
    cout << result << '\n';
    return 0;
}