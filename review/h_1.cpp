#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> test;
int diff;
int N;

int BinarySearch (vector <int> arr, int start, int end, int val)
{
    if (end - start < 1) return start;
    
    int ori_start = start;
    int ori_end = end;

    while (start < end)
    {
        int mid = (start + end) / 2;
        int mid_val = arr[mid];

        if (mid_val < val) {
            start = mid + 1;
        }
        else if (mid_val > val) {
            end = mid - 1;
        }
        else {
            return mid;
        }
    }

    if (start > ori_end) start --;
    if (end > ori_end) end --;
    if (start < ori_start) start ++;
    if (end < ori_start) end ++;

    swap (start, end);
}

int Solution (vector <int> grade, int diff)
{
    sort (grade.begin (), grade.end ());
    int max_count = 1;

    for (int i = 0; i < grade.size (); i++) {
        int count;
        int right_idx = 0;// BinarySearch ();

        count = right_idx - i + 1;

        if (max_count < count) {
            max_count = count;
        }
    }

    return max_count;
}

int main (void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        test.push_back (c);
    }

    cin >> diff;

    cout << Solution (test, diff) << endl;

    return 0;
}