//버블 정렬
//시간복잡도 O(N^2)
#include <stdio.h>
#define N 100

int main(){
  int arr[N], temp;

  for(int i=0; i<N; i++)
    scanf("%d",&arr[i]);

  for(int i=0; i<N-1; i++){ 
    for(int j=0; j<N-1-i; j++){
      //arr[j]<arr[j+1]이면 내림차순 정렬
      if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  return 0;
}