#include <iostream>
#include <deque>
using namespace std;

typedef struct _gift {
    int cnum;
    int prev;
    int next;
} Gift;

int Q, N, M;
int CMD[100001][3];		// opcode, arg1, arg2
// int P[100001];			// Present, index: 선물번호, contents: 컨베이어벨트위치
Gift G[100001];
deque <int> DQ[100001];

void print_input()
{
	cout << endl << "input" << endl;
	cout << CMD[1][0] << " " << N << " " << M << " ";
	for (int i = 1; i <= M; i++) {	// 모든 M개의 선물에 대해서.
		cout << G[i].cnum << " ";
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
		cout << "(" << G[i].cnum << "," << G[i].prev << "," << G[i].next << "), ";
	}
	cout << endl;
}

void input(void)
{
	cin >> Q;
	cin >> CMD[1][0] >> N >> M;
	for (int i = 1; i <= M; i++) {	// 모든 M개의 선물에 대해서.
		cin >> G[i].cnum;
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
		int cn = G[i].cnum;
        if (DQ[cn].size() != 0) {
            int prev = DQ[cn].back();
            G[prev].next = i;
            G[i].prev = prev;
        }
		DQ[cn].push_back(i);
        
	}
}

void transfer_all(int src, int dst)
{
	deque <int> bf;
	int src_size = DQ[src].size();
	for (int i = 0; i < src_size; i++) {
		int tmp = DQ[src].front();
		DQ[src].pop_front();
        G[tmp].prev = 0;
        G[tmp].next = 0;
		bf.push_back(tmp);
	}
	int bf_size = bf.size();
	for (int i = bf_size - 1; i >= 0; i--) {
        if (!DQ[dst].empty()) {
            int next = DQ[dst].front ();
            G[next].prev = bf[i];
            G[bf[i]].next = next;
        }
		DQ[dst].push_front(bf[i]);
		G[bf[i]].cnum = dst;
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
        G[d_front].next = 0;
        G[d_front].prev = 0;

        int d_next = DQ[dst].front ();
        G[d_next].prev = 0;

		DQ[src].push_front(d_front);
		G[d_front].cnum = src;
	}
	else if (!DQ[src].empty() && DQ[dst].empty()) {		// dst만 비어있음.
		int s_front = DQ[src].front();	//cout << "s_front: " << s_front << endl;
		DQ[src].pop_front();
        G[s_front].next = 0;
        G[s_front].prev = 0;

        int s_next = DQ[src].front ();
        G[s_next].prev = 0;

		DQ[dst].push_front(s_front);
		G[s_front].cnum = dst;
	}
	else {
		int s_front = DQ[src].front();	//cout << "s_front: " << s_front << endl;
		int d_front = DQ[dst].front();	//cout << "d_front: " << d_front << endl;
		DQ[src].pop_front();
		DQ[dst].pop_front();
        G[s_front].next = 0;
        G[s_front].prev = 0;
        G[d_front].next = 0;
        G[d_front].prev = 0;
		
        int s_next = DQ[src].front ();
        G[s_next].prev = d_front;
        G[d_front].next = s_next;

        int d_next = DQ[dst].front ();
        G[d_next].prev = s_front;
        G[s_front].next = d_next;
        
		DQ[src].push_front(d_front);
		DQ[dst].push_front(s_front);
		G[d_front].cnum = src;
		G[s_front].cnum = dst;
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
            G[tmp].prev = 0;
            G[tmp].next = 0;
			bf.push_back(tmp);
		}
        int head = DQ[src].front();
        G[head].prev = 0;

		int bf_size = bf.size();
		for (int i = bf_size - 1; i >= 0; i--) {
            if (!DQ[dst].empty()) {
                int next = DQ[dst].front ();
                G[next].prev = bf[i];
                G[bf[i]].next = next;
            }
			DQ[dst].push_front(bf[i]);
			G[bf[i]].cnum = dst;
		}
	}
	cout << DQ[dst].size() << '\n';
}

void get_present_info(int p_num)
{
	if (G[p_num].prev == 0 && G[p_num].next == 0) {		// 앞,뒤로 선물 모두 x.
		int a = -1;
		int b = -1;
		cout << a + 2 * b << '\n';
	}
	else if (G[p_num].prev == 0 && G[p_num].next != 0) {		// 앞에만 선물 x.
		int a = -1;
		int b = G[p_num].next;
		cout << a + 2 * b << '\n';
	}
	else if (G[p_num].prev != 0 && G[p_num].next == 0) {	// 뒤에만 선물 x.
		int a = G[p_num].prev;
		int b = -1;
		cout << a + 2 * b << '\n';
	}
	else if (G[p_num].prev != 0 && G[p_num].next != 0) {
		int a = G[p_num].prev;
		int b = G[p_num].next;
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
	// print_belt();
	// print_present();
	for (int iter = 2; iter <= Q; iter++)
	{
		int op = CMD[iter][0];
		if (op == 200) {
			transfer_all(CMD[iter][1], CMD[iter][2]);
			//print_belt();
			// print_present();
		}
		else if (op == 300) {
			exchange_front(CMD[iter][1], CMD[iter][2]);
			//print_belt();
			// print_present();
		}
		else if (op == 400) {
			share_thing(CMD[iter][1], CMD[iter][2]);
			//print_belt();
			// print_present();
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