/*
Enqueue 큐에 값을 집어넣는 함수
Dequeue 큐에서 값을 빼는 함수
*/
#include <iostream>
#define MAX 100
using namespace std;

int front = -1;
int rear = -1;
int queue[MAX];

//Empty
int IsEmpty(){
  if(front == rear)
    return true;
  else
    return false;
}

//Full
int IsFull(){
  int temp = (rear+1)%MAX;
  if(temp ==front)
    return true;
  else
    return false;
}

//push
void EnQueue(int value){
  if(IsFull())
    cout << "Queue is Full.\n"; 
  else
    rear = (rear+1)%MAX;
    queue[rear] = value;
}

//pop
void DeQueue(){
  if(IsEmpty()){
    cout << "Queue is Empty.\n";
  }
  else{
    front = (front+1)%MAX;
    cout << queue[front] << '\n';
  }
}

int main(){
  EnQueue(4); //rear = 0, front = -1
  EnQueue(7); //rear = 1, front = -1
  EnQueue(12);//rear = 2, front = -1
  DeQueue(); //rear = 2, front = 0
  DeQueue(); //rear = 2, front = 1
  DeQueue(); //rear = 2, front = 2
  DeQueue();
  return 0;
}