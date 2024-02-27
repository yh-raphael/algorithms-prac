#include <iostream>
#include <queue>
using namespace std;
 
#define MAXN (100)
int N, M;//문서수, 궁금한 문서 번호
int P[MAXN+10];//문서 우선순위
 
struct QUE{
    int n, p;//문서번호, 우선순위
};
queue <QUE> que;
int Solve(){
    int seq = 0;
    //0.초기화
    int priocnt[10] = {0};//우선순위별 개수
    que = {};
    //1.우선순위별 개수 파악, 큐에 저장
    for (int i=0; i<N; i++){
        priocnt[P[i]]++;
        que.push({i, P[i]});
    }
    //2.시뮬레이션
    for (int p=9; p>=1; p--){
        while(priocnt[p]){
            QUE cur = que.front(); que.pop();
            if (cur.p == p){//인쇄
                seq++;
                if (cur.n == M) return seq;//궁금한 문서임. 성공
                priocnt[p]--;//인쇄 했으므로 감소
            }
            else{//가장 높은 우선순위 아니므로 큐에 다시 저장
                que.push(cur);
            }
        }
    }
    return -1;//이런 경우 없지만 디버깅을 위해...
}
 
void InputData() {
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> P[i];
    }
}
 
int main() {
    int ans = -1;
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분
 
        ans = Solve();//여기서부터 작성
 
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}
 
/**************************************************************
    Problem: 6808
    Language: C++
    Result: Accepted
    Time:1 ms
    Memory:2244 kb
****************************************************************/