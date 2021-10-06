#include <stdio.h>

int lower_bound(int arr[], int target, int size){
	int mid, start, end;
	start = 0, end = size-1;

	while (end > start){
		mid = (start + end) / 2; 
    // 중간값이 원하는 값보다 크거나 같을 경우, 끝값을 중간값으로 설정하여 다시 탐색한다.
		if (arr[mid] >= target) 
			end = mid;
    // 중간값이 원하는 값보다 작을 경우, 시작값을 중간값+1로 설정하여 다시 탐색한다.
		else 
      start = mid + 1; 
	}
	return end;
}

int upper_bound(int arr[], int target, int size){
	int mid, start, end;
	start = 0, end = size-1;

	while (end > start){
		mid = (start + end) / 2; 
    // 중간값이 원하는 값보다 클 경우, 끝값을 중간값으로 설정하여 다시 탐색한다.
		if (arr[mid] > target) 
			end = mid;
    // 중간값이 원하는 값보다 작거나 같을 경우, 시작값을 중간값+1로 설정하여 다시 탐색한다.
		else 
      start = mid + 1; 
	}
	return end;
}



int lower_bound(int[], int, int);

int main(){
  // 데이터들은 오름차순 배열로 정렬되어있어야 함 (중요)
	int arr[10] = {1, 3, 4, 5, 7, 10, 10, 13, 15, 18};
  
	int target = 10;
	int n = 10;

	printf("lower bound is arr[%d]\n", lower_bound(arr, target, n));
  printf("Upper bound is arr[%d]\n", upper_bound(arr, target, n));

	return 0;
}
