// <set> 은 탐색을 O(NlogN)으로 해줌! index 필요 없고, 있는지 없는지 확인할 때 간편~ Iterator를 잘 활용해야 함!
#include <iostream>
#include <string>       // string tmp = "", tmp += t[i+j].
#include <vector>
#include <climits>      // INT_MAX
#include <set>          // str_set (strs.begin (), strs.end ()), str_set.find (tmp) != str_set.end ().
#include <algorithm>    // min ()
using namespace std;

int dp[20001];

int solution(vector<string> strs, string t)
{
    int answer = 0;     cout << t << endl;
    set <string> str_set (strs.begin (), strs.end ());  // 단어조각들을 빠르게 탐색하기 위함!!
    int len = t.size ();
    
    // dp 배열 초기화!
    for (int i = 0; i < len; i++) {
        dp[i] = INT_MAX;
    }
    
    // dp 뒤에서부터 시작!
    dp[len] = 0;
    for (int i = len-1; i >= 0; i--)
    {
        // 매 순회마다, 단어조각(최대길이:5)과 일치하는 부분이 있는지 비교할 tmp 만들기.
        string tmp = "";
        for (int j = 0; i+j < len && j < 5; j++)
        {
            tmp += t[i+j]; //cout << i << ", " << j << ", " << tmp << endl;
            // set에 있는 단어조각과 일치하는 게 있고! && 그 다음 위치부터 단어를 만들 수 있는 상황이면!
            if (str_set.find (tmp) != str_set.end () && dp[i+j+1] != INT_MAX) {
                dp[i] = min (dp[i], dp[i+j+1] + 1);     // 그 다음 위치 dp값에 +1 !
                //cout << "[i]: " << i << ", " << dp[i] << endl;
            }
        }
    }
    
    // 정답 출력
    if (dp[0] == INT_MAX)
        answer = -1;    // 단어 생성 불가능
    else
        answer = dp[0]; // 최소값 return

    return answer;
}

int main (void) {
    vector <string> strs;
    int result;

    strs.push_back ("ab"); strs.push_back ("na"); strs.push_back ("n"); strs.push_back ("a"); strs.push_back ("bn");
    result = solution (strs, "nabnabn");
    cout << result << '\n';

    strs.clear ();
    strs.push_back ("ba"); strs.push_back ("na"); strs.push_back ("n"); strs.push_back ("a");
    result = solution (strs, "banana");
    cout << result << '\n';

    strs.clear ();
    strs.push_back ("app"); strs.push_back ("ap"); strs.push_back ("p"); strs.push_back ("l"); strs.push_back ("e");
    strs.push_back ("ple"); strs.push_back ("pp");
    result = solution (strs, "apple");
    cout << result << '\n';

    strs.clear ();
    strs.push_back ("ba"); strs.push_back ("an"); strs.push_back ("nan"); strs.push_back ("ban"); strs.push_back ("n");
    result = solution (strs, "banana");
    cout << result << '\n';

    return 0;
}