//MergeSort O(NlogN)
#include <bits/stdc++.h>
using namespace std;

int arr[10] ={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int n = 10;

void Merge(int list[], int left, int mid, int right){
	int temp[10], i, j, k;
	i = left;
	j = mid+1;
	k = left; //k는 temp 배열체크할때만 사용

	while(i<=mid && j<=right){
		if(list[i] <= list[j])
			temp[k++] = list[i++];
		else
			temp[k++] = list[j++];
	}

	while(i<=mid) //13줄 while문에서 비교를 마치고 남아있는 왼쪽 배열의 가장 큰 값을 temp 배열에 삽입
		temp[k++] = list[i++];

	while(j<=right) //13줄 while문에서 비교를 마치고 남아있는 오른쪽 배열의 가장 큰 값을 temp 배열에 삽입
		temp[k++] = list[j++];

	for(int x = left; x<=right; ++x) //temp배열에 넣어두었던 값을 다시 list배열에 넣는 과정
		list[x] = temp[x];
}

void MergeSort(int list[], int left, int right){
	int mid;

	//left값이 right값보다 작을때만 Divide 함수를 호출해줌
	if(left < right){
		mid = (left+right)/2;

		MergeSort(list, left, mid);
		MergeSort(list, mid+1, right);
		Merge(list, left, mid, right);
	}

	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	Divide(arr, 0, n-1);
	for(int i=0; i<n; ++i)	cout << arr[i] << ' ';
	return 0;
}
