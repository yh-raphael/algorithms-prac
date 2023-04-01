#include <iostream>
#include <vector>       // pos.push_back (tmp).
#include <algorithm>    // sort (pos.begin (), pos.end (), cmp).
using namespace std;

int N;
int result = 0;

typedef struct _student {
    int num;
    int like[4];
} student;
vector <student> s_vec;     // index: order.
student stu_arr [21*21];  // index: stu_num;

int map[21][21] = { 0, };
int dr[4] = {0, 0, 1, -1};  // 동,서,남,북
int dc[4] = {1, -1, 0, 0};

typedef struct _position {
    int n_like;
    int n_empty;
    int r;
    int c;
} position;

void print_debug ()
{
    // cout << endl;
    // for (unsigned int i = 0; i < s_vec.size (); i++)
    // {
    //     cout << s_vec[i].num << ": " << s_vec[i].like[0] << ", " << s_vec[i].like[1] << ", "
    //         << s_vec[i].like[2] << ", " << s_vec[i].like[3] << endl;
    // }

    cout << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

int convert_into_score (int like_num)
{
    if (like_num == 0) return 0;
    else if (like_num == 1) return 1;
    else if (like_num == 2) return 10;
    else if (like_num == 3) return 100;
    else if (like_num == 4) return 1000;
}

// for sort function.
bool cmp (position a, position b)
{
    // criterion 1.
    if (a.n_like > b.n_like) {
        return true;
    }
    else if (a.n_like == b.n_like){
        // criterion 2.
        if (a.n_empty > b.n_empty) {
            return true;
        }
        else if (a.n_empty == b.n_empty) {
            // criterion 3.
            if (a.r < b.r) {
                return true;
            }
            else if (a.r == b.r) {
                // criterion 4.
                if (a.c < b.c) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void set_position ()
{
    // for each studnet in order: brute_force!
    for (unsigned int i = 0; i < s_vec.size (); i++)
    {
        vector <position> pos;      // store position infomation: sorting expected.
        int stu_num = s_vec[i].num;
        // table traverse.
        for (int r = 1; r <= N; r++)
        {
            for (int c = 1; c <= N; c++)
            {
                // search the optimization.
                if (map[r][c] != 0) continue;
                int n_like = 0;
                int n_empty = 0;
                // for each adjacent box.
                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    // boundary check.
                    if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
                    // empty or not?
                    if (map[nr][nc] == 0) {
                        n_empty ++;
                    }
                    else {
                        // not empty -> like check! linear search.
                        for (int l = 0; l < 4; l++)
                        {
                            int like_num = s_vec[i].like[l];
                            if (map[nr][nc] == like_num) {
                                n_like ++;
                                break;
                            }
                        }
                    }
                }
                position tmp = { n_like, n_empty, r, c };
                pos.push_back (tmp);
            }
        }
        sort(pos.begin (), pos.end (), cmp);
        int pos_r = pos[0].r;
        int pos_c = pos[0].c;
        map[pos_r][pos_c] = stu_num;
        //print_debug ();
    }
}

// after full allocation!
void calculate_score ()
{
    for (int i = 1; i <= N; i ++)
    {
        for (int j = 1; j <= N; j ++)
        {
            int stu_num = map[i][j];
            int like_sum = 0;
            // for each direction.
            for (int k = 0; k < 4; k ++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];
                // boundary check.
                if (nr < 1 || nr > N || nc < 1 || nc > N) continue;

                // for each like.
                for (int l = 0; l < 4; l ++)
                {
                    int like_num = stu_arr[stu_num].like[l];
                    if (map[nr][nc] == like_num) {
                        like_sum ++;
                        break;
                    }
                }
            }
            result += convert_into_score (like_sum);
        }
    }
}

int main (void)
{
    cin >> N;
    for (int i = 1; i <= N * N; i++)
    {
        int num, a, b, c, d;
        cin >> num >> a >> b >> c >> d;
        student A = {num, a, b, c, d};
        s_vec.push_back (A);                // (1) store student information asap in a vector (ordered).
        stu_arr[num].num = num;             // (2) store student information in an array.
        stu_arr[num].like[0] = a;
        stu_arr[num].like[1] = b;
        stu_arr[num].like[2] = c;
        stu_arr[num].like[3] = d;
    }
    
    set_position ();
    calculate_score ();
    
    cout << result << endl;
    return 0;
}