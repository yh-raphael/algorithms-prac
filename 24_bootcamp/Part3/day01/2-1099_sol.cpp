#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
#define INF ((int)1e7)
int N;//정수개수
int A[MAXN + 10];//입력 정수
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}
int DigitSum(int x){
    int sum=0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int DigitRoot(int x){
    while(x >= 10){
        x = DigitSum(x);
    }
    return x;
}
int Solve(){
    int maxdigit=0, maxv=INF;
    for (int i=0; i<N; i++){
        int r = DigitRoot(A[i]);
        if ((maxdigit < r) || ((maxdigit == r) && (maxv > A[i]))){
            maxdigit = r;
            maxv = A[i];
        }
    }
    return maxv;
}
int main(){
    InputData();
    int ans = Solve();
    cout << ans << endl;
    return 0;
}
 
/**************************************************************
    Problem: 1099
    Language: C++
    Result: Accepted
    Time:3 ms
    Memory:2088 kb
****************************************************************/