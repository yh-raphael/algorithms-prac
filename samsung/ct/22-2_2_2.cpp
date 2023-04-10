#include <iostream>
#include <deque>
using namespace std;

int Q, N, M;
int CMD[100001][3];		// opcode, arg1, arg2
int P[100001];			// Present, index: 선물번호, contents: 컨베이어벨트위치
deque <int> DQ[100001];

void print_input()
{
	cout << endl << "input" << endl;
	cout << CMD[1][0] << " " << N << " " << M << " ";
	for (int i = 1; i <= M; i++) {	// 모든 M개의 선물에 대해서.
		cout << P[i] << " ";
	}
	cout << endl;
	for (int i = 2; i <= Q; i++) {
		int opcode = CMD[i][0];
		if (opcode == 200 || opcode == 300 || opcode == 400) {
			cout << opcode << " " << CMD[i][1] << " " << CMD[i][2] << endl;
		}
		else if (opcode == 500 || opcode == 600) {
			cout << opcode << " " << CMD[i][1] << endl;
		}
	}
}

void print_belt()
{
	cout << endl << "belt" << endl;
	for (int i = 1; i <= N; i++) {
		cout << "#" << i << " : ";
		for (unsigned int j = 0; j < DQ[i].size(); j++) {
			cout << DQ[i][j] << " ";
		}
		cout << endl;
	}
}

void print_present()
{
	cout << endl << "present" << endl;
	for (int i = 1; i <= M; i++) {
		cout << P[i] << " ";
	}
	cout << endl;
}

void input(void)
{
	cin >> Q;
	cin >> CMD[1][0] >> N >> M;
	for (int i = 1; i <= M; i++) {	// 모든 M개의 선물에 대해서.
		cin >> P[i];
	}
	for (int i = 2; i <= Q; i++) {
		cin >> CMD[i][0];
		if (CMD[i][0] == 200 || CMD[i][0] == 300 || CMD[i][0] == 400) {		// 두 개 arg 필요.
			cin >> CMD[i][1] >> CMD[i][2];
		}
		else if (CMD[i][0] == 500 || CMD[i][0] == 600) {	// 한 개 arg만 필요.
			cin >> CMD[i][1];
		}
	}
}


void init_simulation(void)
{
	for (int i = 1; i <= M; i++) {
		int cn = P[i];
		DQ[cn].push_back(i);
	}
}

void transfer_all(int src, int dst)
{
	int src_size = DQ[src].size();
	for (int i = 0; i < src_size; i++) {
		int tmp = DQ[src].back();
		DQ[src].pop_back();

		DQ[dst].push_front(tmp);
		P[tmp] = dst;
	}
	cout << DQ[dst].size() << '\n';
}

void exchange_front(int src, int dst)
{
	if (DQ[src].empty() && DQ[dst].empty()) {			// 둘 다 비어있음.
		cout << DQ[dst].size() << '\n';
		return;
	}
	else if (DQ[src].empty() && !DQ[dst].empty()) {		// src만 비어있음.
		int d_front = DQ[dst].front();	//cout << "d_front: " << d_front << endl;
		DQ[dst].pop_front();

		DQ[src].push_front(d_front);
		P[d_front] = src;
	}
	else if (!DQ[src].empty() && DQ[dst].empty()) {		// dst만 비어있음.
		int s_front = DQ[src].front();	//cout << "s_front: " << s_front << endl;
		DQ[src].pop_front();

		DQ[dst].push_front(s_front);
		P[s_front] = dst;
	}
	else {
		int s_front = DQ[src].front();	//cout << "s_front: " << s_front << endl;
		int d_front = DQ[dst].front();	//cout << "d_front: " << d_front << endl;
		DQ[src].pop_front();
		DQ[dst].pop_front();
		
		DQ[src].push_front(d_front);
		DQ[dst].push_front(s_front);
		P[d_front] = src;
		P[s_front] = dst;
	}
	cout << DQ[dst].size() << '\n';
}

void share_thing(int src, int dst)
{
	if (DQ[src].size() != 1) {
		deque <int> bf;
		int num = DQ[src].size() / 2;	//cout << "num: " << num << endl;
		for (int i = 0; i < num; i++) {
			int tmp = DQ[src].front();
			DQ[src].pop_front();
			bf.push_back(tmp);
		}
		int bf_size = bf.size();
		for (int i = bf_size - 1; i >= 0; i--) {
			DQ[dst].push_front(bf[i]);
			P[bf[i]] = dst;
		}
	}
	cout << DQ[dst].size() << '\n';
}

void get_present_info(int p_num)
{
	int bn = P[p_num];
	int idx = -1;
	for (unsigned int i = 0; i < DQ[bn].size(); i++) {
		if (DQ[bn][i] == p_num) {
			idx = i;
		}
	}

	if (idx == 0 && idx == DQ[bn].size() - 1) {		// 앞,뒤로 선물 모두 x.
		int a = -1;
		int b = -1;
		cout << a + 2 * b << '\n';
	}
	else if (idx == 0 && idx != DQ[bn].size() - 1) {		// 앞에만 선물 x.
		int a = -1;
		int b = DQ[bn][idx + 1];
		cout << a + 2 * b << '\n';
	}
	else if (idx != 0 && idx == DQ[bn].size() - 1) {	// 뒤에만 선물 x.
		int a = DQ[bn][idx - 1];
		int b = -1;
		cout << a + 2 * b << '\n';
	}
	else if (idx != 0 && idx != DQ[bn].size() - 1) {
		int a = DQ[bn][idx - 1];
		int b = DQ[bn][idx + 1];
		cout << a + 2 * b << '\n';
	}
}

void get_belt_info(int b_num)
{
	int b_size = DQ[b_num].size();
	int a, b, c;
	if (b_size == 0) {
		a = -1;
		b = -1;
		c = 0;
	}
	else {
		a = DQ[b_num][0];
		b = DQ[b_num][b_size - 1];
		c = b_size;
	}
	cout << a + 2 * b + 3 * c << '\n';
}

void do_simulation(void)
{
	//print_belt();
	//print_present();
	for (int iter = 2; iter <= Q; iter++)
	{
		int op = CMD[iter][0];
		if (op == 200) {
			transfer_all(CMD[iter][1], CMD[iter][2]);
			//print_belt();
			//print_present();
		}
		else if (op == 300) {
			exchange_front(CMD[iter][1], CMD[iter][2]);
			//print_belt();
			//print_present();
		}
		else if (op == 400) {
			share_thing(CMD[iter][1], CMD[iter][2]);
			//print_belt();
			//print_present();
		}
		else if (op == 500) {
			get_present_info(CMD[iter][1]);
		}
		else if (op == 600) {
			get_belt_info(CMD[iter][1]);
		}
		//if (iter == 8) break;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	init_simulation();
	do_simulation();
	return 0;
}