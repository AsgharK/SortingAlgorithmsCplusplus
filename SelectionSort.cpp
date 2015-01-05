#include <iostream>

void selectionSort(int num[], int length);
void printArray(int num[], int length);

int main(void){
	int num [] = { 89, 5, 62, 16, 8, 10, 34, 45, 19, 2 }; //test array to sort
	/*sizeof(num) returns the size of array in bytes, so we must divide by the size of one element to get number of elements.*/
	int NumOfElements = sizeof(num)/sizeof(num[0]);
	int *p = num; // pointer that points the array
	selectionSort(p,NumOfElements); //call the selectionsort function on the array by passing in pointer
	/*print out the final sorted arry to see if sort has occured correctly*/
	std::cout<<std::endl<<"Final Sorted Array: ";
	printArray(num,NumOfElements); 
	std::cout<<std::endl;

	return 0;
}

//SelectionSort for Descending Order
void selectionSort(int num[], int length){
	int first, temp;
	int count = 0;
	for(int i = length-1; i > 0 ; i--){
		first=0;
		for(int j = 1; j <= i ; j++){
			if(num[j]<num[first]){
				first = j;
			}
		}
		temp = num[first];
		num[first] = num[i];
		num[i] = temp;
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

