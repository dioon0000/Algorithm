//이차원 벡터의 기본 개념 정리
#include <bits/stdc++.h>
using namespace std;

void func1(vector<vector<int>>& v){ //Call By Reference
	v[0][0] = 10;
	return;
}

void func2(vector<vector<int>> v){ //Call By Value
	v[0][1] = 10;
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//각 행, 열을 얼마나 할당해야 할지 알고있을 때
	//10칸을 생성 후 그 안을 vector<int>(5)로 메모리 할당 == arr[10][5]
	vector<vector<int>> v1(10, vector<int>(5));

	//위와 같이 선언과 동시에 메모리 할당까지 마친경우 바로 접근이 가능
	//v1[0].push_back(1)과 같이 이미 메모리 할당이 된것에 push_back으로 접근 시 런타임 에러 발생
	v1[0][0] = 1;	v1[0][1] = 2;	v1[0][2] = 3;	v1[0][3] = 4;	v1[0][4] = 5;

	//-----------------------------------------------------------------------------------------
	
	//각 행, 열을 얼마나 할당해야 할지 모를 때
	//v2라는 이차원 공간만 선언한 것이지 메모리 할당을 하지 않음
	vector<vector<int>> v2;
	vector<int> tmp;
	v2.push_back(tmp); //이 과정이 없다면 벡터의 주소가 존재하지 않으므로 v2[?].push_back() 런타임 에러 발생
	//위와 같이 선언만 해주었다면 push_back()으로 접근하여야 함
	//v2[0][0] = 1과 같이 접근할시 런타임 에러 발생
	v2[0].push_back(1);	v2[0].push_back(2); v2[0].push_back(3);	v2[0].push_back(4); v2[0].push_back(5);

	func1(v1); //Call By Reference : 함수 내에서 벡터값 변환 시 실제 v1값도 바뀜
	for(int i=0; i<5; ++i)
		cout << v1[0][i] << ' ';
	cout << '\n';

	func2(v2); //Call By Vaule : 함수 내에서 벡터값 변환 시 복사된 값이므로 실제 v2값에는 영향을 주지 않음
	for(int i=0; i<5; ++i)
		cout << v2[0][i] << ' ';
	cout << '\n';
	return 0;
}
