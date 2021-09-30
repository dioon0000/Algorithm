#include <stdio.h>

void Merge(int list[], int left, int mid, int right){
	int i, j, k, l, temp[10];
	i = left;
	j = mid+1;
	k = left;
	
	while(i<=mid && j<=right){ //왼쪽 배열 값이 mid를 초과하거나 오른쪽 배열 값이 right를 초과하면 종료
		if(list[i] <= list[j])
			temp[k++] = list[i++];
		else
			temp[k++] = list[j++];
	}
  
  while(i<=mid) 
	  temp[k++] = list[i++];
  while(j<=right) 
	  temp[k++] = list[j++];
  for(int x = left; x<=right; x++) 
	  list[x] = temp[x];
  
}

void MergeSort(int list[], int left, int right){
	int mid;
	
	if(left<right){
		mid = (left+right)/2;
		MergeSort(list, left, mid);
		MergeSort(list, mid+1, right);
		Merge(list, left, mid, right);
	}
}


int main(){
	int arr[10]={10,9,8,7,6,5,4,3,2,1};
	
	MergeSort(arr,0,9);
	
	for(int i=0; i<10; i++)
		printf("%d ",arr[i]);
	return 0;
}