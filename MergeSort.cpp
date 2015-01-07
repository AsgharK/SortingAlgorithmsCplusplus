#include <iostream>

void mergeSort(int num[], int length);
void mergeSort(int num[], int helper[], int low, int high);
void merge(int num[], int helper[], int low, int middle, int high);
void printArray(int num[], int size);

int main(void){
	int num[] = { 89, 5, 62, 16, 8 , 10 , 34, 45, 19, 2 }; //test array to sort
	/*sizeof(num) returns the size of array in bytes, so we must divide by the size of one element to get number of elements.*/
	int NumOfElements = sizeof(num)/sizeof(num[0]);
	/*to see the array before sort*/
	std::cout<<"Array before mergesort: ";
	printArray(num,10);
	int *p = num; // pointer that points the array
	mergeSort(p,NumOfElements);
	/*to see the array after sort*/
	std::cout<<"\nArray after mergesort: ";
	printArray(num,NumOfElements);
	std::cout<<std::endl;

	return 0;
}

void mergeSort(int num[], int length){
	int *helper = new int[length];
	mergeSort(num, helper, 0, length-1);
	delete helper;
}

void mergeSort(int num[], int helper[], int low, int high){
	if(low < high) {
		int middle = (low+high)/2;
		mergeSort(num, helper, low, middle); //this sorts left half
		mergeSort(num, helper, middle+1, high); //this sorts right half
		merge(num, helper, low, middle, high); //this merges them
	}
}

void merge(int num[], int helper[], int low, int middle, int high){
	/*copy both halves into a helper array*/
	for(int i = low; i<=high; i++){
		helper[i] = num[i];
	}

	int helperLeft = low;
	int helperRight = middle + 1;
	int current = low;

	/* 
		Go through helper array and compare the left and right half, copying back the smaller element from
		the two halves into original array
	*/
	while(helperLeft <= middle && helperRight <= high){
		if(helper[helperLeft]<=helper[helperRight]){
			num[current] = helper[helperLeft];
			helperLeft++;
		} else{ //if right element is smaller than left element
			num[current] = helper[helperRight];
			helperRight++;
		}
		current++;
	}
	/*copy the remaining elements of the left side array into the target array*/
	int remaining = middle - helperLeft;
	for(int i=0 ; i<=remaining ; i++){
		num[current+i] = helper[helperLeft+i]; 
	}
}
//print array to go through array and print each element
void printArray(int num[], int size){
	for(int i = 0; i<size; i++){
		std::cout<<num[i]<<" ";
	}
	return;
};