#include <stdio.h>
int main(){
	int target, low, high, mid;
	int data[10] = {2,3,5,7,8,9,11,13,15,20}; //정렬 되어있는 배열
	
	scanf("%d",&target);
	low = 0; //search 대상범위의 첫번째값 
	high = 9; //search 대상범위의 마지막값
	
	while(1){
		if(low<=high){
			mid=(low+high)/2; //mid값 계산 (소수점이하는 자동으로 절삭)
			if(target==data[mid]){
				printf("%d는 %d번째 index에 있습니다.",target,mid);
				break;
			}
			
			if(target<=data[mid]){
				high=mid; //mid값 위 절삭 
			}else{
				low=mid; //mid값 아래 절삭
		 	}
		}else{
			printf("%d는 존재하지 않습니다.",target);
			break;
		}
	}
}