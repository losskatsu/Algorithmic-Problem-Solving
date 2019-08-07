#include <iostream>

using namespace std;

int sum(int n){
	int ret = 0;
	for(int i; i <= n; i++){
		ret = ret + i;
	}
	return ret;
}

int recursiveSum(int n){
	if(n==1) return 1; 
	return n + recursiveSum(n-1); 
}

int main()
{
	int a = 10;

	int res_sum;
	int res_rec;

	res_sum = sum(a);
	res_rec = recursiveSum(a);

	cout << res_sum << endl;
	cout << res_rec << endl;

	return 0;
}	
