//Counting Sort
#include <stdio.h>
#define MAX 10000
int main() {
  int n, temp;
  int arr[MAX]={0,};

  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&temp);
    arr[temp-1]++;
  }

  for(int i=0; i<MAX; i++){
    //배열의 크기가 0일때, for문 생략을 위한 조건문
    if(arr[i]!=0)
      for(int j=0; j<arr[i]; j++){
        printf("%d ",i+1);
      }
  }
  return 0;
}