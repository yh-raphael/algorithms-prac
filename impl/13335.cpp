// *** Implementation Idea -> sophisticated *** //
#include <iostream>
#include <queue>        // queue <int> q; q.front (), q.pop (), q.push (arr[i]);
using namespace std;

int main (void)
{
    int N, W, L; cin >> N >> W >> L;
    int arr[1001] = { 0, };
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    queue <int> q;
    int count = 0, total_weight = 0;
    for (int i = 1; i <= N; i++)
    {
        while (1)
        {
            if (q.size () == (unsigned int) W) {
                total_weight -= q.front ();         // if the bridge is full!
                q.pop ();
            }
            if (total_weight + arr[i] <= L)
                break;
            q.push (0);     // '0' means an unit gap between trucks!
            count ++;
        }
        total_weight += arr[i];
        q.push (arr[i]);
        count ++;
    }
    cout << count + W << '\n';
    return 0;
}