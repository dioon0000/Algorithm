#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수
//부모노드는 idx/2이고 자식노드 중 왼쪽 노드는 2*idx, 오른쪽 노드는 2*idx+1
//최소 힙 우선순위 큐 구현

//O(lgN)
void push(int x){
	heap[++sz] = x;
	int idx = sz;
  
	while(idx>1){
		int tmpIdx = idx/2;
    //부모노드를 확인 했을때 자식노드보다 값이 작다면 최대힙을 만족하므로 더 검사하지 않고 반복문 종료
		if(heap[tmpIdx] <= heap[idx])	break;
		swap(heap[tmpIdx], heap[idx]);
		idx = tmpIdx;
	}
}
//O(1)
int top(){
	if(sz!=0)
		return heap[1];
	else
		return -1;
}
//O(lgN)
void pop(){
	int idx = 1;
	heap[idx] = heap[sz--];
  
  //현재 idx값이 리프에 도달할때까지 반복문 실행
	while(2*idx <= sz){
    //lc = left Child, rc = right Child
		int lc = 2*idx, rc = 2*idx+1;
		int minIdx = lc;
    //lc는 존재하지만 rc는 존재하지 않는경우가 있으므로 확인 후 값이 더 작다면 minIdx를 rc값으로 변경
		if(rc <= sz && heap[rc] < heap[lc])
			minIdx = rc;
    //부모노드를 확인 했을때 자식노드보다 값이 작다면 최대힙을 만족하므로 더 검사하지 않고 반복문 종료
		if(heap[idx] <= heap[minIdx])	break;
		swap(heap[idx], heap[minIdx]);
		idx = minIdx;
	}
}

void priorityQueue(){
	push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
	cout << top() << '\n'; // 2
	pop(); // {10, 5, 9}
	pop(); // {10, 9}
	cout << top() << '\n'; // 9
	push(5); push(15); // {10, 9, 5, 15}
	cout << top() << '\n'; // 5
	pop(); // {10, 9, 15}
	cout << top() << '\n'; // 9
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
  
	priorityQueue();
  return 0;
}
