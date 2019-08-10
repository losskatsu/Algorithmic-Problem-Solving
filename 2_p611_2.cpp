#include <iostream>
#include <array>

using namespace std;



int main()
{
    int size = 10;
	int capacity = 10;
	int M = 2;
	int data[10] = {2,4,6,7,8,7,6,5,33,88}; 
	int* array1 = data; 
	
	int newValue = 99;
	//check array element 
	
	cout << "This is old array" << endl;
	for(int i=0; i<10; i++){
		cout << array1[i] << endl;
	}
	
	cout << "" << endl;
	cout << "" << endl;
	
	if(size==capacity){
		int newCapacity = capacity + M; 
		int* newArray = new int[newCapacity]; 
		for(int i=0; i<size; ++i)
			newArray[i] = array1[i];
		//if(array1) delete [] array1;
		array1 = newArray;
		capacity = newCapacity;
	}

	array1[size++] =  newValue; 
	
	cout << "This is new array" << endl;
	for(int i=0 ; i<size ; i++){
		cout << array1[i] << endl;
	}
	
	return 0;
}

