#include <iostream>

void bubbleSort(int num[], int length);
void printArray(int num[], int length);

int main(void){
	int num [] = { 89, 5, 62, 16, 8, 10, 34, 45, 19, 2 }; //test array to sort
	/*sizeof(num) returns the size of array in bytes, so we must divide by the size of one element to get number of elements.*/
	int NumOfElements = sizeof(num)/sizeof(num[0]);
	int *p = num; // pointer that points the array
	bubbleSort(p,NumOfElements); //call the bubblesort function on the array by passing in pointer
	/*print out the final sorted arry to see if sort has occured correctly*/
	std::cout<<std::endl<<"Final Sorted Array: ";
	printArray(num,NumOfElements); 
	std::cout<<std::endl;

	return 0;
}

//BubbleSort for Descending Order
void bubbleSort(int num[], int length){
	int flag = 1; //flag is 1 to start the first phase
	int temp; //holding variable
	int count = 0; //keep track number of step/swaps made, this isnt needed, just here for test purposes 
	for(int i = 1;i <= length && flag; i++){
		flag = 0; //flag set to 0 here, if swap does not occure, array already sorted, flag stays at 0
		for(int j = 0; j < (length-1); j++){
			if(num[j+1] > num[j]){
				count++;//increments step number
				temp = num[j];
				num[j]  = num[j+1];
				num[j+1] = temp;
				flag=1; //since swap occured, array is not sorted, set flag to 1
				/*print out array at this step, this isnt needed, just here for test purposes*/
				std::cout<<std::endl<<"Step "<<count<<": ";
				printArray(num,length);
			}
		}
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

