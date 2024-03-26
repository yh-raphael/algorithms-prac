#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
 
int P;
char N1[10000+10];
char N2[10000+10];
int L[10000+10];
char farm;
int sol;
 
int sol_cow[128];
struct route{
    char target;
    int dist;
};
vector<struct route> node[128];
 
int visited[128];   // 매 소마다 초기화 해줘야 함!
struct state{
    vector<char> v;
    int cnt;
    int sum;
    char pos;
};
 
void PrintSol() {
    for (char i='A'; i<'Z'; i++) {
        if (sol_cow[i] == 0) continue;
        if (sol_cow[i] == INT_MAX) continue;
        cout << i << ": " << sol_cow[i] << endl;
    }
}
void PrintGraph() {
    for (char i='A'; i<='z'; i++) {
        if (!node[i].size()) continue;
        cout << i << " -> ";
        for (int j=0; j<node[i].size(); j++) {
            cout << "(" << node[i][j].target << "," << node[i][j].dist << ") ";
        } cout << endl;
    }
}
void BuildGraph() {
    for (int i=0; i<P; i++) {
        char s = N1[i];
        char e = N2[i];
        int d = L[i];
        // 각 노드 별로 route 정보를 push 해줌.
        node[s].push_back({e, d});
        node[e].push_back({s, d});
    }
}
int DoBFS(char start)
{
    if (node[start].size() == 0) return INT_MAX;
 
    // cout << "----" << start <<"-----"<<endl;
    fill(visited, visited+128, INT_MAX);
    int min_sum = INT_MAX;
    queue<struct state> Q;
 
    state first;
    first.v.push_back(start);
    first.cnt = 0;
    first.sum = 0;
    first.pos = start;
    Q.push(first);  visited[start] = first.sum;
 
    while (!Q.empty()) {
        vector<char> cur_v; cur_v = Q.front().v;
        int cur_cnt = Q.front().cnt;
        int cur_sum = Q.front().sum;
        char cur_pos = Q.front().pos;
        Q.pop();
 
        // cout << "cur_pos: " << cur_pos << ", cur_sum: " << cur_sum << endl;
        // 목장 도착!
        if (cur_pos == 'Z') {
            if (min_sum > cur_sum) {
                min_sum = cur_sum;      // 최단 걸린 시간으로 갱신!
            }
            continue;
        }
 
        // 모든 이웃에 대하여 push!
        for (int i=0; i<node[cur_pos].size(); i++) {
            char next_target = node[cur_pos][i].target;
            int next_dist = node[cur_pos][i].dist;
 
            // cout << "next_dist: " << next_dist << endl;
            int next_cnt = cur_cnt + 1;
            int next_sum = cur_sum + next_dist;
            if (visited[next_target] < next_sum) continue;  // 이미 더 작은 sum으로 방문 했음.
            char next_pos = next_target;
            vector<char> next_v = cur_v; next_v.push_back(next_target);
 
            // cout << "next_pos: " << next_pos << ", next_sum: " << next_sum << endl;
            Q.push({next_v, next_cnt, next_sum, next_pos}); visited[next_pos] = next_sum;
        }
    }
    return min_sum;
}
void Solve()
{
    //1. 일단 graph를 빌드하자.
    BuildGraph();
    // PrintGraph();
 
    //2. 각 소에 대해 BFS: 최단거리 resolve!
    for (char i='A'; i<'Z'; i++) {
        int min_sum = DoBFS(i);     // 없는 소는 바로 continue 함!
        sol_cow[i] = min_sum;       // 임의의 소에 대한 최단 이동 시간을 저장.
    }
 
    //3. 누가 가장 빨리 가는가?
    farm = 0;
    sol = INT_MAX;
    for (char i='A'; i<'Z'; i++) {
        if (sol > sol_cow[i]) {
            sol = sol_cow[i];
            farm = i;
        }
    }
    // PrintSol();
}
 
void InputData(){
    cin >> P;
    for (int i=0; i<P; i++){
        cin >> N1[i] >> N2[i] >> L[i];
    }
}
int main(){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    Solve();
 
    cout << farm << " " << sol << endl;// 출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1176
    Language: C++
    Result: Accepted
    Time:52 ms
    Memory:2420 kb
****************************************************************/