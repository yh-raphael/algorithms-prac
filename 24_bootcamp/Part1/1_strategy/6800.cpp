#include <iostream>
using namespace std;

char str[100000 + 10];//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 문자열

void InputData(){
	cin >> str;
}

int Solve()
{
    int cnt=0, bal=0;
    for (int i=0; str[i]; i++) {
        if (str[i] == '(') {
            bal++;
        }
        else {
            bal--;
            if (str[i-1] == '(') cnt += bal;
            else cnt += 1;
        }
    }
    return cnt;
}

int main() {
	int ans;
	InputData();//입력
	
	//여기서부터 작성
    ans = Solve();
	
	cout << ans << endl;//출력
	return 0;
}