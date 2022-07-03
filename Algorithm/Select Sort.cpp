//Select Sort O(N^2)
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int arr[10] ={3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
	int n=10;

	for(int i=0; i<10; ++i){
		int min_idx = i;

		for(int j=i+1; j<10; ++j){
			if(arr[min_idx] > arr[j])
				min_idx = j;
		}
		swap(arr[min_idx], arr[i]);
	}

	/*
	12~20줄의 코드는 아래와 같이 변형 가능
	for(int i=0; i<10; ++i)
		swap(*min_element(arr+i, arr+10), arr[i]);
	*/

	for(int i=0; i<10; ++i)
		cout << arr[i] << ' ';

	return 0;
}
