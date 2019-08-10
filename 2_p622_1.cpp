#include <iostream>
#include <list>

using namespace std; 

void josephus(int n, int k){
	list<int> survivors; 
	//리스트 준비
	for(int i=1; i<=n; ++i) survivors.push_back(i); 

	//이번에 죽을 사람
	list<int>::iterator kill=survivors.begin(); 
	while(n>2){
		kill = survivors.erase(kill);
		if(kill == survivors.end()) kill = survivors.begin(); 
		--n; 
		for(int i=0; i<k-1; ++i){
			++kill;
			if(kill==survivors.end()) kill = survivors.begin(); 
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
}


int main()
{
	int N = 6;
	int K = 3; 
	
	josephus(N, K); 


	return 0;
}
