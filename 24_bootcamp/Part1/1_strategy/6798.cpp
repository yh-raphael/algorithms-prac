#include <iostream>
using namespace std;

#define MAX (100000)
int N;//정수
int C[MAX];//분자 배열
int P[MAX];//분모 배열

void Solve()
{
    for (int i=2; i<=N; i++) {  //분모
        for (int j=1; j<i; j++) {   //분자
            int index = (j * MAX) / i;
            if (P[index] != 0) continue;
            C[index] = j;
            P[index] = i;
        }
    }
}

void InputData(){ 
	cin >> N; 
}
void OutputData(){
    cout << "0/1" << endl;
    for (int i=0; i<MAX; i++) {
        if (P[i] == 0) continue;
        cout << C[i] << "/" << P[i] << endl;
    }
    cout << "1/1" << endl;
}
int main() {
	InputData();//입력
	
	//여기서부터 작성
    Solve();
	OutputData();
	return 0;
}