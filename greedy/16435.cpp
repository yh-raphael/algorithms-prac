// 스네이크버드

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, L;
    cin >> N >> L;
    
    vector<int> V(N);
    
    for (int i=0; i<N; i++)
        cin >> V[i];
    
    sort(V.begin(), V.end());
    
    for (int i=0; i<N; i++)
    {
        if (V[i] <= L)
            L += 1;
    }
    
    cout << L << '\n';
    return 0;
}