#include <iostream>
#include <deque>
#include <vector>
#include <queue>
using namespace std;
 
int S, E;//출발 정류장 번호, 도착 정류장 번호
deque<int> prime;
int arr[10000];
int visited[10000];
vector<vector<int>> V;
struct node{
    int num;
    int cnt;
};
 
bool IsNeighbor(int p, int n)
{
    int numm = p;
    if (p == n) return false;
    int pp[4] = {0,0,0,0};
    int nn[4] = {0,0,0,0};
 
    pp[0] = p / 1000; p %= 1000;
    pp[1] = p / 100; p %= 100;
    pp[2] = p / 10; p %= 10;
    pp[3] = p;
 
    nn[0] = n / 1000; n %= 1000;
    nn[1] = n / 100; n %= 100;
    nn[2] = n / 10; n %= 10;
    nn[3] = n;
 
    int cnt = 0;
    for (int i=0; i<4; i++) {
        if (pp[i] == nn[i]) {
            cnt ++;
        }
    }
    if (cnt == 3) return true;  // 세 개가 같으면 인접!
    else return false;          // 아니면 false!
}
void PrintGraph()
{
    for (int i=0; i<prime.size(); i++) {
        cout << "prime: " << prime[i] << " -> ";
        for (int j=0; j<V[i].size(); j++) {
            cout << V[i][j] << ' ';
        }
        cout << endl;
    }
}
void BuildGraph()
{
    for (int i=0; i<prime.size(); i++) {
        vector<int> tmp;
        // 임의의 prime[i]에 대해 인접 노드 빌드.
        for (int j=0; j<prime.size(); j++) {
            if (IsNeighbor(prime[i], prime[j])) {
                tmp.push_back(prime[j]);
            }   // 인접 노드만 찾아서 tmp vector 빌드.
        }
        V.push_back(tmp);   // 총 1061번 push!
        arr[prime[i]] = i;  // index map!
    }
}
 
void PrintPrime()
{
    for (int i=0; i<prime.size(); i++) {
        cout << prime[i] << ' ';
    } cout << endl;
    cout << "num of prime: " << prime.size() << endl;
}
void TrimPrime()
{
    while (!prime.empty()) {
        if (prime[0] < 1000) prime.pop_front();
        else if (prime[0] >= 1000) break;
    }
}
void ResolvePrime()
{
    for (int num=2; num <= 9999; num++) {
        bool flag = true;
        for (int i=0; i<prime.size(); i++) {
            if (num % prime[i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) prime.push_back(num);
    }
}
 
int DoBFS(int s, int e)
{
    queue<struct node> Q;
 
    struct node first = {s, 0};
    Q.push(first); visited[s] = 1;
    while (!Q.empty()) {
        int cur_num = Q.front().num;
        int cur_cnt = Q.front().cnt;
        int V_idx = arr[cur_num];
 
        // cout << "cur_num: " << cur_num << ", cur_cnt: " << cur_cnt << endl;
        if (cur_num == e) return cur_cnt;   // 정답!!!
 
        for (int i=0; i<V[V_idx].size(); i++) {
            int next_num = V[V_idx][i];
            int next_cnt = cur_cnt + 1;
 
            if (visited[next_num] == 1) continue;       // 가봤으면 가지 말라고!!
            struct node next = {next_num, next_cnt};
            Q.push(next); visited[next_num] = 1;
        }
        Q.pop();
    }
 
    // 여기까지 도달할 수 없음?!
    return -3;
}
int Solve()
{
    int sol = -2;
    ResolvePrime();
    TrimPrime();
    // PrintPrime();
 
    BuildGraph();
    // PrintGraph();
     
    sol = DoBFS(S, E);
    return sol;
}
 
void InputData(){
    cin >> S >> E;
}
int main(){
    int ans = -1;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = Solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}
/**************************************************************
    Problem: 1160
    Language: C++
    Result: Accepted
    Time:52 ms
    Memory:2312 kb
****************************************************************/