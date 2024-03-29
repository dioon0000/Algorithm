//야매 리스트 구현이므로 코테에만 사용할 것
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX]; //data, pre_iter, next_iter를 나타내는 배열
int unused = 1;

//List 삽입기능 함수
void insert(int addr, int num) {
    //dat 값 생성
    dat[unused] = num;
    //pre 값 생성
    pre[unused] = addr;
    //nxt 값 생성
    nxt[unused] = nxt[addr];
    //addr의 nxt값과 nxt[addr] pre값을 현재 unused주소로 변경
    if(nxt[addr] != -1)
        pre[nxt[addr]] = unused;

    nxt[addr] = unused;

    unused++;
}

//List 삭제기능 함수
void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];

    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

//dat의 값을 모두 출력하는 함수
void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
} 
