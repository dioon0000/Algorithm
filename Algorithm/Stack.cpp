#include <iostream>
#include <cstring>
#define SIZE 10000
using namespace std;

int Stack[SIZE];
int max_value = -1;
//스택이 비어있는지 알려줌
int empty(){
    if(max_value==-1){
        return 1;
    }
    return 0;
}
//push 함수는 스택의 가장 위에 Data값을 넣는 함수
void push(int data){
    max_value++;
    Stack[max_value]=data;
}
//pop 함수는 스택 가장 위에 값을 빼내는 함수
void pop(){
    int temp = 0;
    if(!empty()){
        temp = Stack[max_value];
        cout << temp << endl;
        max_value--;
    }
    else {
        printf("-1\n");
    }
}
//현재 스택의 크기를 알려줌
void size(){
    if(!empty()){
        cout << max_value+1 << endl;
    }
    else{
        cout << "0" << endl;
    }
}
//가장 위에 값이 무엇인지 알려줌
void top(){
    if(!empty()){
        cout << Stack[max_value] << endl;
    }
    else {
        cout << "-1" << endl;
    }
}
int main(){
    char *text = new char[10];
    int x, data;//14
    cin >> x;
    for(int i=0; i<x; i++){
        cin >> text;
        if(strcmp("pop",text)==0){
            pop();
        }
        else if(strcmp("push",text)==0){
            cin >> data;
            push(data);
        }
        else if(strcmp("size",text)==0){
            size();
        }
        else if(strcmp("empty",text)==0){
            cout <<empty() <<endl;
        }
        else if(strcmp("top",text)==0){
            top();
        }
    }
    delete[] text;

    return 0;
} 
