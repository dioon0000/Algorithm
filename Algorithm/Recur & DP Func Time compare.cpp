#include <iostream>
#include <chrono>
using namespace std;

//재귀 Algorithm을 이용한 피보나치 수열 O(2^N)
long long fibo_r(int n){
    if(n<=1)
        return n;
    return fibo_r(n-1)+fibo_r(n-2);
}

//DP Algorithm을 이용한 피보나치 수열 O(N)
long long fibo_d(int n){
    long long a=0, b=1, c=1;
    if(n==1)
        return a;
    else if(n==2)
        return b;
    else{
        for(int i=0; i<n-2; ++i){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main() {
    //Default Value : 10
    int n = 10;
    //et 값만 출력하기 위해 각각의 재귀, DP에서 리턴해주는 값을 저장할 임시 변수
    long long tmp;
    //C++에서 사용하는 ns 측정 함수
    chrono::time_point<chrono::high_resolution_clock> start, end;
    //et = end - start
    chrono::duration<double, nano> et;
    //무한 루프
    while(true){
        //함수 시작 시간 측정
        start = chrono::high_resolution_clock::now();
        tmp = fibo_r(n);
        //함수 끝 시간 측정
        end = chrono::high_resolution_clock::now();
        et = end - start;
        //600초에 해당하는 나노초 값
        if(et.count() > 600000000) break;
        //재귀 함수의 시간
        cout << "Recursive Func Time : " << et.count() << "ns\n";
        //함수 시작 시간 측정
        start = chrono::high_resolution_clock::now();
        tmp = fibo_d(n);
        //함수 끝 시간 측정
        end = chrono::high_resolution_clock::now();
        et = end - start;
        //600초에 해당하는 나노초 값
        if(et.count() > 600000000) break;
        //DP 함수의 시간
        cout << "Dynamic Programing Func Time : " << et.count() << "ns\n";
        //두 함수에서 10분을 넘어가지 않았다면 n값을 10 올려서 다시 측정
        n+=10;
    }

    cout <<"n값이 "<< n << "일 때, 10분을 초과하여 종료되었습니다";
    return 0;
}
