// 이게 greedy로 풀 수 있는 것을 알아차리는 게 핵심! Written on 2023-02-25-Sat.
#include <iostream>
#include <vector>       // vector <pair <int, int> > ranking;
#include <algorithm>    // sort (ranking.begin (), ranking.end ());
using namespace std;

int main (void)
{
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector <pair <int, int> > ranking;
        int N; cin >> N;
        for (int j = 0; j < N; j++)
        {
            int A, B; cin >> A >> B;
            // ranking.push_back ({A, B});
            ranking.push_back (make_pair (A, B));   
        }

        // cout << '\n';
        // for (int j = 0; j < N; j++)
        //     cout << ranking[j].first << ' ' << ranking[j].second << '\n';
        // cout << '\n';

        sort (ranking.begin (), ranking.end ());

        // cout << '\n';
        // for (int j = 0; j < N; j++)
        //     cout << ranking[j].first << ' ' << ranking[j].second << '\n';
        // cout << '\n';

        int cur_second = ranking[0].second;
        int result = 1;
        for (int j = 1; j < N; j++)
        {
            if (ranking[j].second < cur_second) {
                result ++;
                cur_second = ranking[j].second;
            }
            // cout << cur_second << '\n';
        }

        cout << result << '\n';
    }
    return 0;
}