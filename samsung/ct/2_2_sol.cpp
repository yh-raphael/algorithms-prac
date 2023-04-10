#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;
int Q, N, M;
struct BOX {
    int idx;            // 자신의 상자 번호
    BOX* prev, * next;  // 앞과 뒤 상자
} box[100005];
struct BELT {
    BOX* front, * end;  // 가장 앞과 가장 뒤 상자
    int cnt;            // 총 상자 개수
} belt[100005];
void push_box_back(int belt_idx, BOX* box) {  // belt_idx번 벨트 뒤에 box 를 추가하는 함수
    belt[belt_idx].cnt++;
    if (belt[belt_idx].front == NULL) {  // 만약 비어있는 벨트 였다면?
        box->prev = box->next = NULL;
        belt[belt_idx].front = belt[belt_idx].end = box;
    }
    else {
        box->prev = belt[belt_idx].end, box->next = NULL;
        belt[belt_idx].end->next = box;
        belt[belt_idx].end = box;
    }
}
void push_box_front(int belt_idx, BOX* box) {  // belt_idx번 벨트 앞에 box 를 추가하는 함수
    belt[belt_idx].cnt++;
    if (belt[belt_idx].front == NULL) {  // 만약 비어있는 벨트 였다면?
        box->prev = box->next = NULL;
        belt[belt_idx].front = belt[belt_idx].end = box;
    }
    else {
        box->prev = NULL, box->next = belt[belt_idx].front;
        belt[belt_idx].front->prev = box;
        belt[belt_idx].front = box;
    }
}
void input() {
    cin >> Q;
    int x;
    cin >> x >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> x;  // i 번 상자가 어느 벨트에 있는 지 입력
        box[i].idx = i;
        push_box_back(x, &box[i]);
    }
}
BOX* drop_box(int i) {  // i 번 벨트의 앞쪽 상자를 pop 하는 함수
    BOX* box = belt[i].front;
    belt[i].front = box->next;
    box->next = NULL;
    if (belt[i].front != NULL)
        belt[i].front->prev = NULL;
    else belt[i].end = NULL;
    belt[i].cnt--;
    return box;
}
int query_200(int src, int dst) {  // O(1)
    // 1. 두 벨트 전부 비어있는 경우
    if (belt[src].cnt == 0 && belt[dst].cnt == 0) {
        return 0;
    }
    // 2. src 벨트가 비어서 옮길 게 없는 경우
    else if (belt[src].cnt == 0) {
        return belt[dst].cnt;
    }
    // 3. dst 벨트가 비어있는 경우
    else if (belt[dst].cnt == 0) {
        belt[dst] = belt[src];
        belt[src] = { NULL, NULL, 0};
    }
    // 4. 이외의 경우
    else {
        // 1. belt[src].end 와 belt[dst].front 사이에 link 생성
        belt[dst].front->prev = belt[src].end;
        belt[src].end->next = belt[dst].front;
        // 2. belt[dst]의 front 를 belt[src].front 로 변경
        belt[dst].front = belt[src].front;
        belt[src].front = belt[src].end = NULL;
        // 3. 각 belt의 개수 관리
        belt[dst].cnt += belt[src].cnt;
        belt[src].cnt = 0;
    }
}
int query_300(int src, int dst) {  // O(1)
    BOX* box_src = NULL, * box_dst = NULL;
    if (belt[src].cnt > 0) {
        box_src = drop_box(src);
    }
    if (belt[dst].cnt > 0) {
        box_dst = drop_box(dst);
    }
    if (box_src) {
        push_box_front(dst, box_src);
    }
    if (box_dst) {
        push_box_front(src, box_dst);
    }
    return belt[dst].cnt;
}
int query_400(int src, int dst) {  // O(M)
    stack<BOX*> st;
    // 1. src 에서 상자를 절반만큼 뽑아냅니다.
    int move_cnt = belt[src].cnt / 2;
    for (int rep = 1; rep <= move_cnt; rep++) {
        st.push(drop_box(src));
    }
    // 2. 뽑아낸 순서의 역순으로 dst의 앞에 넣어줍ㄴ디ㅏ.
    while (!st.empty()) {
        BOX* box = st.top(); st.pop();
        push_box_front(dst, box);
    }
    return belt[dst].cnt;
}
int query_500(int p_num) {  // O(1)
    int a = -1, b = -1;
    BOX* tgt = &box[p_num];
    if (tgt->prev) a = tgt->prev->idx;
    if (tgt->next) b = tgt->next->idx;
    return a + 2 * b;
}
int query_600(int b_num) {  // O(1)
    int a = -1, b = -1, c = 0;
    if (belt[b_num].front) a = belt[b_num].front->idx;
    if (belt[b_num].end) b = belt[b_num].end->idx;
    c = belt[b_num].cnt;
    return a + 2 * b + 3 * c;
}
void pro() {
    for (int rep = 2; rep <= Q; rep++) {
        int query;
        cin >> query;
        if (query == 200) {
            int src, dst;
            cin >> src >> dst;
            cout << query_200(src, dst) << '\n';
        }
        else if (query == 300) {
            int src, dst;
            cin >> src >> dst;
            cout << query_300(src, dst) << '\n';
        }
        else if (query == 400) {
            int src, dst;
            cin >> src >> dst;
            cout << query_400(src, dst) << '\n';
        }
        else if (query == 500) {
            int p_num;
            cin >> p_num;
            cout << query_500(p_num) << '\n';
        }
        else if (query == 600) {
            int b_num;
            cin >> b_num;
            cout << query_600(b_num) << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    pro();
    return 0;
}