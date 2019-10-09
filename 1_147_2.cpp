#include <iostream> 

using namespace std; 

int sum(int n){
	int ret = 0;
	for(int i=1; i<n; i++){
		ret += i;
	}
	return ret; 
}

int recursiveSum(int n){
	if(n==1) return 1;
	int ret = 0;
	ret = n + recursiveSum(n-1);
	return  ret;
}

int main(void)
{
	int n = 10;
	int res  = recursiveSum(n);
	cout << res <<endl;
	return 0;
}
