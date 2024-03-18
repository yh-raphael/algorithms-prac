#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;
int used[MAXN + 10];
void InputData(){
    cin >> N;
}
int DigitSquare(int x){
    int sum = 0;
    while(x){
        int num = x%10;
        sum += num * num;
        x /= 10;
    }
    return sum;
}
int HappyNum(int x){
    used[x] = 1;
    while(x != 1){
        x = DigitSquare(x);
        if (used[x]++) return 0;//행복한 수 아님
    }
    return 1;//행복한 수
}
int Solve(){
    int i;
    for (i=N; i>0; i--){
        if (used[i]) continue;
        if (HappyNum(i) == 1) break;
    }
    return i;
}
int main(){
    InputData();
    int ans = Solve();
    cout << ans << endl;
    return 0;
}
 
/**************************************************************
    Problem: 1101
    Language: C++
    Result: Accepted
    Time:2 ms
    Memory:2088 kb
****************************************************************/