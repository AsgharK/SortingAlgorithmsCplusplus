#include <iostream>

void quickSort(int num[], int left, int right);
int partition(int num[], int left, int right);
void printArray(int num[], int length);

int main(void){
	int num[] = { 89, 5, 62, 16, 8 , 10 , 34, 45, 19, 2 }; //test array to sort
	/*sizeof(num) returns the size of array in bytes, so we must divide by the size of one element to get number of elements.*/
	int NumOfElements = sizeof(num)/sizeof(num[0]);
	/*to see the array before sort*/
	std::cout<<"Array before quicksort: ";
	printArray(num, NumOfElements);
	int *p = num; // pointer that points the array
	quickSort(p, 0, NumOfElements-1);//call quicksort on pointer
	/*to see the array after sort*/
	std::cout<<"\nArray after quicksort: ";
	printArray(num, NumOfElements);
	std::cout<<std::endl;

	return 0;
}

void quickSort(int num[], int left, int right){
	int index = partition(num, left, right);
	/*
		recursive calls to quickSort that keeps partitioning the array and has all the elements less then
		partition index move to left and greater then move to right.
	*/
	if(left < index-1){
		quickSort(num, left, index-1);
	}
	if(index < right){
		quickSort(num, index, right);
	}
}
int partition(int num[], int left, int right){
	int pivot = num[(left+right)/2];//choose a pivot point
	int temp;
	while(left <= right) {
		/*find elements on the left that need to be on the right*/
		while(num[left] < pivot){
			left++;
		}
		/*find elements on the right that need to be on the left*/
		while(num[right] > pivot){
			right--;
		}
		/*swap the elements, move left and right indices*/
		if(left <= right){
			temp = num[left];
			num[left] = num[right];
			num[right] = temp;
			left++;
			right--;
		}
	}
	return left;
}
//print array to go through array and print each element
void printArray(int num[], int length){
	for(int i = 0; i < length; i++){
		std::cout<<num[i]<<" ";
	}
	return;
};