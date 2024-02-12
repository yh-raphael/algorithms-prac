#include <iostream>
using namespace std;

int R;//원의 반지름

int Solve()
{
    int cnt = 0;
    for (int x=1; x<=R; x++) {
        for (int y=1; y<=R; y++) {
            if (x*x + y*y <= R*R) {
                cnt++;
            }
        }
    }
    return cnt * 4;
}

void InputData(){
	cin >> R;
}

int main() {
	int ans;
	InputData();//입력
	
	//여기서부터 작성
    ans = Solve();
	
	cout << ans << endl;//출력
	return 0;
}