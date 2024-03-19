#include <iostream>
using namespace std;
 
struct cord {
    int x,y;
};
cord A[25+10];
int B[25+10];
int bingo[12+10];
int cnt=0;
 
void CheckBingo(int bnum)
{
    const int X = A[bnum].x;
    const int Y = A[bnum].y;
    //1. 가로 행 체크
    bingo[X]++;
    if (bingo[X] == 5) cnt++;
    //2. 세로 열 체크
    bingo[Y+5]++;
    if (bingo[Y+5] == 5) cnt++;
    //3. 우하향 대각선 체크
    if (X == Y) {
        bingo[11]++;
        if (bingo[11] == 5) cnt++;
    }
    //4. 우상향 대각선 체크
    if (X+Y == 6) {
        bingo[12]++;
        if (bingo[12] == 5) cnt++;
    }
}
bool IsEnd()
{
    return (cnt >= 3);
}
int Solve()
{
    for (int i=1; i<=25; i++) {
        //1.빙고판 체크
        CheckBingo(B[i]);
        //2.끝?
        if (IsEnd()) {
            return i;
        }
    }
    return -1; // 도달 할 수 없음.
}
 
void InputData(){
    int tmp = 0;
    for (int i=1; i<=5; i++){
        for (int j=1; j<=5; j++){
            cin >> tmp;
            A[tmp].x = i;
            A[tmp].y = j;
        }
    }
    for (int i=1; i<=25; i++){
        cin >> B[i];
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    ans = Solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}