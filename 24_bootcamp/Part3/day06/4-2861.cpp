#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int N;//히스토그램수
int H[100000+10];//히스토그램 높이
struct Data {
    int h;
    int idx;
};
bool InputData() {
    cin >> N;
    if (N == 0) return false;
     
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    return true;
}
long long Solve()
{
    vector<long long> candidate;
    stack <Data> ST;
 
    ST.push({H[0], 0});
    for (int i=1; i<N; i++) {
        int ref_idx = i;    // pop시키면서 가장 최근에 pop한 index를 저장 (pop 안 하면 자기 인덱스!)
        // 숫자가 큰 막대정보는 다 pop 처리
        while (!ST.empty() && ST.top().h > H[i]) {
            ref_idx = ST.top().idx;
            long long area = (long long)ST.top().h * (long long)(i - ST.top().idx);
            candidate.push_back(area);
            ST.pop();
        }
        // Push
        if (!ST.empty() && ST.top().h == H[i]) continue;    // 같으면 예외처리!
        ST.push({H[i], ref_idx});
    }
    // 마지막 pop 처리!
    int i = N;
    while (!ST.empty()) {
        long long area = (long long)ST.top().h * (long long)(i - ST.top().idx);
        candidate.push_back(area); //cout << "i: "<<i<<", "<<"area: "<<area<<endl;
        ST.pop();
    }
    return *max_element(candidate.begin(), candidate.end());
}
int main() {
    long long ans = -1;
    while(InputData()){//입력받는 부분
 
        //여기서부터 작성
        ans = Solve();
 
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}