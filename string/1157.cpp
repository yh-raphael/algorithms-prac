#include <iostream>
#include <string>

using namespace std;

int a_cnt[26] = { 0, };

int main (void)
{
    string str; cin >> str;
    for (unsigned int i = 0; i < str.length (); i++)
    {
        if (0 <= str[i] - 'a' && str[i] - 'a' <= 26)
            a_cnt[str[i] - 'a']++;
        if (0 <= str[i] - 'A' && str[i] - 'A' <= 26)
            a_cnt[str[i] - 'A']++;
    }

    int max = 0;
    int max_idx = -1;
    for (unsigned int i = 0; i < 26; i++)
    {
        if (max < a_cnt[i]) {
            max = a_cnt[i];
            max_idx = i;
        }
    }
    int dup_cnt = 0;
    for (unsigned int i = 0; i < 26; i++)
    {
        if (max == a_cnt[i])
            dup_cnt ++;
    }

    if (dup_cnt > 1)
        cout << '?' << '\n';
    else
        cout << (char) ('A' + max_idx) << '\n';
    return 0;
}