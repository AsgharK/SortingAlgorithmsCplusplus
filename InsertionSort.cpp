#include <iostream>

void insertionSort(int num[], int length);
void printArray(int num[], int length);

int main(void){
	int num [] = { 89, 5, 62, 16, 8, 10, 34, 45, 19, 2 }; //test array to sort
	/*sizeof(num) returns the size of array in bytes, so we must divide by the size of one element to get number of elements.*/
	int NumOfElements = sizeof(num)/sizeof(num[0]);
	int *p = num; // pointer that points the array
	insertionSort(p,NumOfElements); //call the insertionsort function on the array by passing in pointer
	/*print out the final sorted arry to see if sort has occured correctly*/
	std::cout<<std::endl<<"Final Sorted Array: ";
	printArray(num,NumOfElements); 
	std::cout<<std::endl;

	return 0;
}

//InsertionSort for Descending Order
void insertionSort(int num[], int length){
	int j,key;
	int count = 0;
	for(int i = 1; i < length ; i++){ //start at 1
		key = num[i];
		for(j = i-1; j >= 0 && num[j] < key; j--){ //this for loop moves the smaller values up
			num[j+1] = num[j];
		}
		num[j+1] = key; //put the key value in the right spot
		/*print out array at this step, this isnt needed, just here for test purposes*/
		std::cout<<std::endl<<"Step "<<++count<<": ";
		printArray(num,length);
	}
	/*
		since a pointer pointing to the original array was sent, 
		that array itself has been sorted and you do not have to return a new sorted array
	*/
	return;
}

//print array to go through array and print each element
void printArray(int num[], int length){
	for(int i = 0; i < length; i++){
		std::cout<<num[i]<<" ";
	}
	return;
};
