//Bubble Sort O(N^2)
#include <bits/stdc++.h>
#define N 10
using namespace std;

int main(){
    int arr[N], temp;

    for(int i=0; i<N; i++)
        cin >> arr[i];

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

    for(int i=0; i<N; ++i)
        cout << arr[i] << ' ';
    return 0;
}
