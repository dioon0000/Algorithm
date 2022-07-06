//Counting Sort O(N)
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp;
    int arr[MAX]={0, };

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        arr[temp-1]++;
    }

    for(int i=0; i<MAX; i++)
        //배열의 크기가 0일때, for문 생략을 위한 조건문
        if(arr[i]!=0)
            for(int j=0; j<arr[i]; j++)
                cout << i+1 << ' ';

    return 0;
}
