//QuickSort 평균 : O(NlogN), 최악 : O(N^2)
#include <bits/stdc++.h>
using namespace std;

int arr[10] = {4, 1, 2, 3, 9, 7, 8, 6, 10, 5};
int n = 10;

void quick_sort(int list[], int start, int end){
    // 원소가 1개인 경우 
    if(start>=end)    return;
    int pivot = list[start];
    // 왼쪽 출발 지점
    int l = start+1;
    // 오른쪽 출발 지점 
    int r = end;

    // 포인터가 엇갈릴때까지 반복
    while(1){
        //pivot값보다 list[l]값이 크지않다면 l값을 오른쪽으로 옮김
        while(l<=end && pivot>=list[l])
            l++;
        //pivot값보다 list[r]값이 작지않다면 r값을 왼쪽으로 옮김
        while(r>start && pivot<=list[r])
            r--;

        //엇갈렸을때
        if(l>r){
            swap(list[start], list[r]);
            break;
        }
        //l과 r이 pivot기준 정상범위 내에서 멈췄을 때
        else{
            swap(list[l], list[r]);
            break;
        }
    }
    // 분할 계산 
    quick_sort(list, start, r-1);
    quick_sort(list, r+1, end);
} 
  int main(){
    quick_sort(arr, 0, n-1); 

    // Result Check
    for(int i=0; i<10; i++) cout << arr[i] << ' ';

    return 0; 
  }
