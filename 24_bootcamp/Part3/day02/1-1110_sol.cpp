#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
 
struct ST {
    int r, c;
};
ST adress[25 + 2];
 
int A[5 + 10][5 + 10];
int B[25 + 10];
 
int row[5];
int col[5];
int cro[2];
 
void Init() {
    memset(row, 0, sizeof(row)); //string.h
    fill(col, col + 5, 0); // algorithm
    for (int i = 0; i < 2; i++) {
        cro[i] = 0;
    }
}
void InputData() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
            adress[A[i][j]] = { i,j };
        }
    }
    for (int i = 0; i < 25; i++) {
        cin >> B[i];
    }
}
 
int Solve() {
    int bingo = 0;
    for (int cnt = 0; cnt < 25; cnt++) {
        // 빙고 좌표 확인
        int br = adress[B[cnt]].r;
        int bc = adress[B[cnt]].c;
 
        // 빙고 체크
        row[br]++;
        col[bc]++;
        if (br == bc) {
            cro[0]++;
            if (cro[0] == 5) bingo++;
        }
        if (br + bc == 4) {
            cro[1]++;
            if (cro[1] == 5) bingo++;
        }
        if (row[br] == 5) bingo++;
        if (col[bc] == 5) bingo++;
        //3빙고 이상인지 확인
        if (bingo >= 3) return cnt + 1;
    }
    return -1;
}
 
int main() {
    int ans = -1;
    InputData();// 입력받는 부분
     
    // 여기서부터 작성
    Init();
    ans = Solve();
 
    cout << ans << endl;// 출력하는 부분
    return 0;
}