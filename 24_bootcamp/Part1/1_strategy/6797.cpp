#include <iostream>
#include <algorithm>
using namespace std;

int N;

int Karprekar(int num)
{
    int d[4];
    //1. 4자리로 분해.
    for (int i=0; i<4; i++) {
        d[i] = num % 10;
        num /= 10;
    }
    //2. sorting-오름차순.
    sort(d, d+4);
    //3. diff값 구하기.
    return (d[3]*1000 + d[2]*100 + d[1]*10 +d[0]) -
        (d[0]*1000 + d[1]*100 + d[2]*10 + d[3]);
}
int Solve()
{
    int cnt=0, num=N;
    while (num != 6174) {
        num = Karprekar(num);
        cnt++;
    }
    return cnt;
}

void InputData(){
	cin >> N;
}

int main(){
	int ans = -1;
	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = Solve();

	cout << ans << endl;// 출력하는 부분

	return 0;
}